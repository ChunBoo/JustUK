#include<vector>
#include<unordered_map>
#include<iostream>
#include<queue>
//http://www.cppblog.com/avcpp/articles/139979.html
using VEC=std::vector<int>;
using MAP=std::unordered_map<int,int>;
using PAIR=std::pair<int,int>;
class Solution
{
    public:
        VEC topKFrequent(const VEC& nums,int k)
        {
            MAP m{};
            for(auto &v:nums)
                m[v]+=1;
            
            struct myComparison
            {
                bool operator()(PAIR& p1,PAIR& p2){return p1.second>p2.second;}   //less heap
            };
            
            std::priority_queue<PAIR,std::vector<PAIR>,myComparison> q{};
            for(auto &a:m)
            {
                q.push(a);
                if(q.size()>k)
                    q.pop();
            }
            VEC res{};
            while(!q.empty())
            {
                res.push_back(q.top().first);
                q.pop();
            }
            return res;            
        }
};

int main()
{
    VEC nums{12,388,1,2,2,3,33,4,4};
    VEC ans=Solution().topKFrequent(nums,2);
    for(auto &v:ans)
        std::cout<<v<<',';
}


