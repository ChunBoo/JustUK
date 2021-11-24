//bs for the first specific number from a vector
#include<iostream>
#include<vector>

int checkEqual(std::vector<int>& nums,int pos)
{
    return nums[pos];
}

int findFirstValue(std::vector<int>& nums,int v)
{
    int left=0;
    int right=nums.size()-1;
        int mid=(left+right)/2;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(checkEqual(nums,mid)<v)
            left=mid+1;
        else    
            right=mid-1;
    }
    return mid;
}

int main()
{
    std::vector<int> nums{0,0,2,2,2,1,1,1};
    int pos=findFirstValue(nums,1);
    std::cout<<"The first pos in nums of 1 is: "<<pos<<'\n';
    return 0;
}