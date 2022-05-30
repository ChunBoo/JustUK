#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<vector>

using DT=std::vector<int>;

class CCompare
{
    private:
        int m_g;
    public:
        CCompare(int g):m_g{g}{}
        bool operator()(int a,int b) const
        {
            if(m_g)
                return a>b;
            return a<b;
        }
};

DT arrayRanking(const DT& nums)
{
    CCompare larger(true);

    std::set<int,CCompare> s(larger);  //create a set to filter nums with descending order
    for(auto i:nums)
        s.insert(i);

    // DT temp{};
    // for(auto &i:s)
    //     temp.push_back(i);

    std::map<int,int> m{};
    std::set<int>::iterator iter{s.begin()};

    for(int idx=0;iter!=s.end();++iter,++idx)
        m[*iter]=idx;
    DT ans{};
    // for(auto &i:nums)
        // ans.push_back(m[i]);
    for(int i=0;i<nums.size();++i)
    {
        ans.push_back(m[nums[i]]);
    }
    return ans;
}


int main()
{
    DT nums{50,60,90,100,100};
    DT res=arrayRanking(nums);
    for(auto &v:res)
        std::cout<<v<<',';
    return 0;
}