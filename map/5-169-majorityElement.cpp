/**
 * Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m{};
        for(const int num:nums)
            if(++m[num]>n/2) return num;
        return -1;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        srand(time(nullptr));
        const int n=nums.size();
        while(true)
        {
            const int index=rand()%n;
            const int majority=nums[index];
            int count=0;
            for(const int num:nums)
            {
                if(num==majority&&++count>n/2) return num;
            }
        }
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(),nums.begin()+nums.size()/2,nums.end());
        return nums[nums.size()/2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums,0,nums.size()-1);
    }
private:
    int majorityElement(const vector<int>& nums,int l,int r)
    {
        if(l==r) return nums[l];
        const int m=l+(r-l)/2;
        const int ml=majorityElement(nums,l,m);
        const int mr=majorityElement(nums,m+1,r);
        if(ml==mr)
            return ml;
        return count(nums.begin()+l,nums.begin()+r+1,ml)>
                count(nums.begin()+l,nums.begin()+r+1,mr)?ml:mr;
    }
};