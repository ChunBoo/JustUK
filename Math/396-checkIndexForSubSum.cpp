//given one array of integers, return the index which can split the array as two parts with same sum
#include<vector>
#include<iostream>
#include<numeric>
using VEC=std::vector<int>;
int checkIndex(const VEC& nums)
{
  int n=nums.size();
  int total=std::accumulate(nums.begin(),nums.end(),0);
  int left=0,right=total;
  for(int i=0;i<n;++i)
  {
    right-=nums[i];
    if(right==left)
        return i;
    left+=nums[i];   //substract current element later for the case of single member,likes nums=[2]
  }
  return -1;
}

int main()
{
    VEC nums{1,3,4,0,5,2,2};
    std::cout<<checkIndex(nums);
}