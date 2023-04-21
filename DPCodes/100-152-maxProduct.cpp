#include<iostream>
#include<vector>
#include<algorithm>
using std::cout;
using VEC=std::vector<int>;
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        // VEC fMax(nums),fMin(nums);
        int fMax,fMin;
        fMax=fMin=nums[0];
        for(int i=1;i<n;++i)
        {
            fMax=max(fMax*nums[i],max(fMin*nums[i],nums[i]));  //or fMax[i]=max(fMax[i-1]*nums[i],max(fMin[i-1]*nums[i],nums[i]));
            fMin=min(fMin*nums[i],min(fMax*nums[i],nums[i]));  //or fMin[i]=min(fMin[i-1]*nums[i],min(fMax[i-1]*nums[i],nums[i]));
        }
        return fMax;
    }
};



int main()
{
    VEC nums{-2,3,-4};
    int res=Solution().maxProduct(nums);
    cout<<res;
}