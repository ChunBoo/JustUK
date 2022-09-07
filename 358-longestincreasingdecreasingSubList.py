"""_summary_
You are given a list of integers nums. Return the length of the longest sublist such that its length is at least 3 
and its values are strictly increasing and then decreasing. Both the increasing part and the decreasing part 
must be non-empty.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [7, 1, 3, 5, 2, 0]
Output
5
Explanation
The sublist [1, 3, 5, 2, 0] is strictly increasing then decreasing.

Example 2
Input
nums = [1, 2, 3]
Output
0
"""


def longestincreasingdecreasingSubList(nums):
    sz=len(nums)
    inc=[1]*sz
    dec=[1]*sz
    for i in range(1,sz):
        if(nums[i]>nums[i-1]):
            inc[i]+=inc[i-1]
    for i in range(sz-2,-1,-1):
        if(nums[i]>nums[i+1]):
            dec[i]+=dec[i+1]
    ans=0    
    for i in range(sz):
        if(inc[i]>1 and dec[i]>1):
            ans=max(ans,inc[i]+dec[i]-1) #dynamic programming
    return ans


nums=[2,3,1,3,5,3,0,1,3,2,2]
print(longestincreasingdecreasingSubList(nums))