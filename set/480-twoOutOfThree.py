'''
Given three integer arrays nums1, nums2, and nums3, return a distinct array containing 
all the values that are present in at least two out of the three arrays. You may return the values in any order.
Example 1:
Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
Output: [3,2]
Explanation: The values that are present in at least two arrays are:
- 3, in all three arrays.
- 2, in nums1 and nums2.
'''
from collections import Counter
def twoOutOfThree(nums1,nums2,nums3):
    s1=set(nums1)
    s2=set(nums2)
    s3=set(nums3)
    
    return list(s1&s2|s2&s3|s1&s3)

def twoOutOfThree2(nums1,nums2,nums3):
    d=Counter(list(set(nums1))+list(set(nums2))+list(set(nums3)))
    return [k for k,v in d.items() if v>1 ]

def twoOutOfThree3(nums1,nums2,nums3):    
    s1=set(nums1)
    s2=set(nums2)
    s3=set(nums3)
    ans=set()
    for i in s1:
        if i in s2 or i in s3:
            ans.add(i)
    for j in s2:
        if j in s3:
            ans.add(j)
    return list(ans)
n1=[1,1,3,2]
n2=[2,3]
n3=[3]
print(twoOutOfThree(n1,n2,n3))
print(twoOutOfThree2(n1,n2,n3))
print(twoOutOfThree3(n1,n2,n3))