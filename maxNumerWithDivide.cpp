#include<iostream>
#include<vector>

// get the maximum number from a vector with divide-and-conquer 

class Solution
{
    public:
        int maxNumber(std::vector<int>& nums)
        {
            int leftMax;
            int rightMax;
            int sz=nums.size();
            if(sz==1)
                return nums[0];
            if(nums.empty())
                return 0;

            std::vector<int> left;
            std::vector<int> right;
            
            int mid=sz/2;
            for(int i=0;i<mid;++i)
                left.push_back(nums[i]);
            for(int i=mid;i<sz;++i)
                right.push_back(nums[i]);
            leftMax=maxNumber(left);
            rightMax=maxNumber(right);
            return leftMax>rightMax?leftMax:rightMax;
        }
};

int main()
{
    std::vector<int> nums{2,0,69,3,-1,9,4};
    Solution s;
    int max=s.maxNumber(nums);
    std::cout<<"Max= "<<max;
    return 0;
}