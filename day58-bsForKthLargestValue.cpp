//bs for the kth largest number

#include<iostream>
#include<vector>
#include<cmath>

int countOfLargerThanMid(std::vector<int>& nums,int x)
{
    int ans=0;
    for(auto i:nums)
    {
        if(i>=x)
            ans+=1;
    }
    return ans;
}

int findTheKthLargestNumber(std::vector<int>& nums,int k)
{
    int min=0;
    int max=0;
    for(auto i:nums)
    {
        if(i<min)
            min=i;
        if(i>max)
            max=i;
    }

    while(min<=max)
    {
        int mid=(min+max)/2;
        int cnt=countOfLargerThanMid(nums,mid);
        if(cnt>=k)
            min=mid+1;
        else
            max=mid-1;
    }
    return max;
}

int main()
{
    std::vector<int> nums{3,2,4,5,1};
    int result=findTheKthLargestNumber(nums,2);
    std::cout<<"The value is: "<<result<<'\n';

    return 0;
}