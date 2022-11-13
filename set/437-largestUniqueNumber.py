"""
 an integer array nums, return the largest integer that only occurs once. If no integer occurs once, return -1.

Example 1:
Input: nums = [5,7,3,9,4,9,8,3,1]
Output: 8
Explanation: The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it is the answer.

Example 2:
Input: nums = [9,9,8,8]
Output: -1
Explanation: There is no number that occurs only once.

Constraints:
1 <= nums.length <= 2000
0 <= nums[i] <= 1000

Hints:
Find the number of occurrences of each value.
Use an array or a hash table to do that.
Look for the largest value with number of occurrences = 1.
"""
from collections import Counter
def largestNumber(nums):
    n=len(nums)
    if n==0:
        return -1
    c=Counter(nums)
    ans=-1
    for k,v in c.items():
        if v==1:
            if ans<k:
                ans=k
    return ans

# nums=[5,7,3,9,4,9,8,3,1]
nums=[9,9,8,8]
print(largestNumber(nums))
