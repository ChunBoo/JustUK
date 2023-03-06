class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        n=len(nums)
        neg=bisect_left(nums,0)
        p=n-bisect_right(nums,0)
        # for i,v in enumerate(nums):
        #     if v<0:
        #         neg+=1
        #     elif v>0:
        #         p=n-i
        #         break

        # return max(neg,p)
        # for i in nums:
        #     if i==0:
        #         s=i
        return max(p,neg)
    
    
[-2,-1,-1,1,2,3]