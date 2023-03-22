#include<vector>
#include<iostream>
#include<algorithm>
using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;
using std::cout;


MATRIX threeSum(const VEC& nums)
{
    std::sort(nums.begin(),nums.end());
    MATRIX ans{};
    int n=nums.size();
    for(int i=0;i<n;++i)
    {
        if(nums[i]>0)
            return ans;
        if(i>0 &&(nums[i]==nums[i-1]))  continue;
        int l=i+1,r=n-1;
        while(l<r)
        {
            int tSum=nums[i]+nums[l]+nums[r];
            if(tSum==0)
            {
                VEC tmp{nums[i],nums[l],nums[r]};
                ans.push_back(tmp);
                while(l<r &&(nums[l]==nums[l+1])){l+=1;}
                while(l<r &&(nums[r]==nums[r-1])){r-=1;}
                l+=1;
                r-=1;
            }
            else if(tSum>0)
            {
                r-=1;
            }
            else
                l+=1;
        }
    }
    return ans;
}
int main()
{
    VEC nums{-1,0,1,2,-1,-4};
    MATRIX res=threeSum(nums);
    for(auto &v:res)
    {
        cout<<'[';
        for(auto &i:v)
            cout<<i<<',';
        cout<<']';
    }
}