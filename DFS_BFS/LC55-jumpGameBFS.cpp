#include<iostream>
#include<vector>
#include<deque>
#include<set>
using VEC=std::vector<int>;


bool canJump(const VEC& nums)
{
    int n=nums.size();
    if(n==1)
        return true;
    std::deque<int> q{0}; //store the indexes
    std::set<int> seen{};
    while(!q.empty())
    {
        int cur=q.front();
        q.pop_front();
        for(int i=0;i<=nums[cur];++i)
        {
            int next=i+cur;
            if(next<n&&seen.find(next)==seen.end())
            {
                if((nums[next]+next)>=n-1)
                    return true;

                q.push_back(next);
                seen.insert(next);
            }

        }
    }
    return false;
}

int main()
{
    VEC nums{3,2,4,0,0};
    std::cout<<canJump(nums);
}