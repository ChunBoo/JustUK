"""_summary_
   You are given a list of integers nums and integers lo and hi. Return the number of sublists A such that lo ≤ max(A) ≤ hi.

Constraints
0 ≤ n ≤ 100,000 where n is the length of nums

Example 1
Input
nums = [1, 5, 3, 2]
lo = 1
hi = 4
Output
4

Explanation
We have the following sublists where 1 ≤ max(A) ≤ 4
[1]
[3]
[3, 2]
[2]
We can count the number of sublists that has maximum less than a upperbound R, e.g. f(R), 
and we also count the number of sublists with max less or equal than L-1 i.e. f(L-1) and the answer would be f(R)-f(L-1)
"""


def foo(nums,L,R):
    def f(upperBound):
        cur=ans=0
        for i in nums:
            if i<=upperBound:
                cur+=1
            else:
                cur=0
            ans+=cur
        return ans
    h=f(R)
    l=f(L-1)
    return f(R)-f(L-1)


def f(nums,L,R):
    ans=0
    n=len(nums)
    for i in range(n):
        for j in range(i,n):
            s=nums[i:j+1]
            if L<=max(s) and R>=max(s):
                print(s)
                ans+=1
    return ans


nums=[0,1,5,3,4]
print(f(nums,3,4))
print("----------")
print(foo(nums,3,4))