#include<iostream>
#include<vector>
#include<cmath>
using std::cout;
using VEC=std::vector<int>;

int foo(int i,int j,const VEC& nums1,const VEC& nums2)
{
    if(i<0||j<0)
        return 0;
    if(nums1[i]==nums2[j])
    {
        return foo(i-1,j-1,nums1,nums2)+1;
    }
    else
        return std::max(foo(i-1,j,nums1,nums2),foo(i,j-1,nums1,nums2));
}

int maxUncrossedLines(const VEC& nums1,const VEC& nums2)
{
    return foo(nums1.size()-1,nums2.size()-1,nums1,nums2);
}

int main()
{
    VEC nums1{2,5,1,2,5},nums2{10,5,2,1,5,2};
//     nums1 = [2,5,1,2,5]
// nums2 = [10,5,2,1,5,2]
    cout<<maxUncrossedLines(nums1,nums2);
}