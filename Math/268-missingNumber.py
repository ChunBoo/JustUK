
'''
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example, Given nums = [0, 1, 3] return 2.

Note: Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
'''

def missingNumber(nums):
    n=len(nums)
    expectedSum=(n+1)*n//2
    currentSum=sum(nums)
    return expectedSum-currentSum

#another method is XOR
int missingNumber(int[] nums) {
        int miss = 0;
        for (int i = 0; i < nums.length; i ++) {
            miss = miss ^ i + 1;
            miss = miss ^ nums[i];
        }
        return miss;
    }
nums = [0, 1, 3]
print(missingNumber(nums))