#include<iostream>
#include<vector>

class Solution
{
    public:
        std::vector<int> mergeSort(std::vector<int>& nums)
        {
            if(nums.size()==1||nums.empty())
                return nums;

            int mid=nums.size()/2;

            std::vector<int> left;
            std::vector<int> right;
            for(int i=0;i<mid;++i)
                left.push_back(nums[i]);
            for(int i=mid;i<nums.size();++i)
                right.push_back(nums[i]);
            
            left=mergeSort(left);
            right=mergeSort(right);

            std::vector<int> retVector;
            for(int i=0;i<nums.size();++i)
            {
                if(i<mid)
                    retVector.push_back(left[i]);
                else
                    retVector.push_back(right[i]);
            }
            return retVector;
        }
};


int main()
{
    std::vector<int> nums{3,2,5,9,2,4,1};
    Solution s;
    std::vector<int> ret=s.mergeSort(nums);
    for(auto i:ret)
        std::cout<<i<<"-";
    return 0;
}