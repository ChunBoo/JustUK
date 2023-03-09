#include<iostream>
#include<vector>

using std::cout;
using VEC=std::vector<int>;

int getCommon(const VEC& nums1,const VEC& nums2)
{
    int l1=nums1.size();
    int l2=nums2.size();
    int l=0,r=0;
    while(l<l1 &&r<l2)
    {
        if(nums1[l]==nums2[r])
            return nums1[l];
        else if(nums1[l]<nums2[r])
            l+=1;
        else
            r+=1;
    }
    return -1;
}

int main()
{
    VEC nums1{1,2,3,6};
    VEC nums2{2,3,4,5};
    cout<<getCommon(nums1,nums2);
}