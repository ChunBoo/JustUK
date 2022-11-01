#include<vector>
#include<iostream>

using VEC=std::vector<int>;

void reverse(VEC& nums, int l,int r)
{
    while(l<r)
    {
        int tmp=nums[l];
        nums[l]=nums[r];
        nums[r]=tmp;
        l+=1;
        r-=1;
    }
}

void rota(VEC& nums,int k)
{
    int n=nums.size();
    k%=n;
    reverse(nums,0,n-1);
    reverse(nums,0,k-1);
    reverse(nums,k,n-1);
}

int main()
{
    VEC nums{1,2,3,4,5,6};
    for(auto &v:nums)
        std::cout<<v<<',';
    rota(nums,3);
    for(auto &v:nums)
        std::cout<<v<<',';

}
