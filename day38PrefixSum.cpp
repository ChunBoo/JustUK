#include<iostream>
#include<vector>

int prefixSum(std::vector<int>& nums,int start,int end)
{
    int ans=0;
    int sum=0;
    if(nums.empty())
        return ans;
    
    std::vector<int> tempSum;
    tempSum.push_back(0);
    
    for(int i=0;i<nums.size();++i)
    {
        sum+=nums[i];
        tempSum.push_back(sum);
    }

    return tempSum[end+1]-tempSum[start];
}

int main()
{
    std::vector<int> nums{1,2,3,7,9};
    int start=0,end=2;
    std::cout<<"Result=: "<<prefixSum(nums,start,end);
    return 0;
}