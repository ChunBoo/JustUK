'''
Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element, or false otherwise. If the array is already strictly increasing, return true. The array nums is strictly increasing if nums[i – 1] < nums[i] for each index (1 <= i < nums.length).

Example 1:
Input: nums = [1,2,10,5,7]
Output: true
Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
[1,2,5,7] is strictly increasing, so return true.

Example 2:
Input: nums = [2,3,1,2]
Output: false
Explanation:
[3,1,2] is the result of removing the element at index 0.
[2,1,2] is the result of removing the element at index 1.
[2,3,2] is the result of removing the element at index 2.
[2,3,1] is the result of removing the element at index 3.
No resulting array is strictly increasing, so return false.

Example 3:
Input: nums = [1,1,1]
Output: false
Explanation: The result of removing any element is [1,1].
[1,1] is not strictly increasing, so return false.

Constraints:
2 <= nums.length <= 1000
1 <= nums[i] <= 1000

Hints:
For each index i in nums remove this index.
If the array becomes sorted return true, otherwise revert to the original array and try different index.
'''

class Solution:
    def canBeIncreasing(self, nums):
        cnt=0
        for i in range(len(nums)):
            arr = nums[:i] + nums[i + 1:]
            if not self.is_strictly_increasing(arr):
                cnt+=1
        return cnt>=1
    
    def is_strictly_increasing(self,arr):
        #return sorted(arr) == arr and len(arr) == len(set(arr))
        return all(arr[i] < arr[i + 1] for i in range(len(arr) - 1))
    
    
    def canIncreasing(self,nums):#dp method
        n=len(nums)
        dp=[1]*n
        for i in range(n):
            for j in range(i):
                if nums[j]<nums[i]:
                    dp[i]=max(dp[i],dp[j]+1)
        return max(dp)+1>=n
    
    def foo(self,nums):
        lis=[]
        for i in nums:
            x=bisect.bisect_left(lis,i)
            if x==len(lis):
                lis.append(x)
            else:
                lis[x]=i
        return len(lis)+1>=len(nums)

s=Solution()
nums=[2,3,10,7,8]
print(s.canBeIncreasing(nums))
print(s.canIncreasing(nums))
# print(s.foo(nums))