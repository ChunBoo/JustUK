#include<iostream>
#include<vector>
using std::cout;
using VEC=std::vector<int>;


VEC searchRan(const VEC& nums,int target)
{
    int n=nums.size();
    if(n==0)
        return VEC{-1,-1};
    if(target<nums[0]||target>nums[n-1])
        return VEC{-1,-1};
    VEC ans{-1,-1};
    int l=0,r=n-1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(target==nums[mid])
        {
            int s=mid,e=mid;
            while(s>0 && nums[s]==nums[s-1]) s-=1;
            while((e<n)&& nums[e]==nums[e+1]) e+=1;
            return VEC{s,e};
        }
        else if(target>nums[mid])
            l+=1;
        else r-=1;
        // else
    }
    return VEC{-1,-1};
}

int main()
{
    VEC nums{0,1,2,3,3,5,6,7};  //the array should be sorted as non-descending order
    VEC res=searchRan(nums,3);
    for(auto v:res)
        cout<<v<<',';
}