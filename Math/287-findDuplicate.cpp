/**
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?
*/
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int l=1, r=nums.size();
        while(l<r){
            const int m=l+(r-l)/2;
            int count=0;
            for(int x:nums)
                if(x<=m)++count;
            if(count>m)
                r=m;
            else
                l=m+1;
        }
        return l;
    }
};

class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<int(nums.size());++i){
            int x=abs(nums[i]);
            if(nums[x]<0) return x;
            nums[x]=-nums[x];
        }
        return -1;
    }
};
class Solution3 {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(fast!=slow);
        int entry=0;
        while(entry!=slow){
            slow=nums[slow];
            entry=nums[entry];
        }
        return entry;
    }
};

int findDuplicateNumber(vector<int>& nums){
    for(int i=0;i<int(nums.size());++i){
        int x=abs(nums[i]);
        if(nums[x]<0) return x;
        nums[x]=-nums[x];
    }
    return -1;
}

int main()
{
    vector<int> nums{1,3,4,2,2};
    cout<<findDuplicateNumber(nums);
}