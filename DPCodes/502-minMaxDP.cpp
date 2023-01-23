#include<iostream>
#include<vector>

using VEC=std::vector<int>;

int f(int i,int j,const VEC& nums)
{
    if(i==j)
        return nums[i];
    return std::max(nums[i]-f(i+1,j,nums),nums[j]-f(i,j-1,nums));
}

int minMaxDP(const VEC& nums)
{
    int n=nums.size();
    return f(0,n-1,nums)>0;
}

int main()
{
    

VEC C{1,10,1};//{1,3,2,6};
// c=[1,10,1]
std::cout<<(minMaxDP(C));
}