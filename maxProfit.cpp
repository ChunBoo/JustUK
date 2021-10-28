#include<vector>
#include<iostream>
#include<string>
#include<cmath>
//dp problem

class Solution
{
    public:
        int maxProfit(std::vector<int>& values)
        {
            if(values.empty())
                return 0;
            int ans=0;
            int dpi=0;
            for(auto i:values)
            {
                dpi=std::max(dpi+i,i);
                ans=std::max(dpi,ans);
            }
            return ans;
        }
};

int main()
{
    std::vector<int> ivec{1,2,-10,4,5};
    Solution s;
    int maxProfit=s.maxProfit(ivec);
    std::cout<<maxProfit<<'\n';

    return 0;
}