class Solution(object):
    def minMaxGame(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        g=min
        while n>1:
            for i in range(0,n//2):
                nums[i]=g(nums[i*2],nums[i*2+1])
                g=max if g==min else min
            n//=2
        return nums[0]
        # def f(arr):
        #     n=len(arr)
        #     if n==1:
        #         return arr[0]
        #     a=[]
        #     g=min
        #     for i in range(0,n,2):
        #         a.append(g(arr[i],arr[i+1]))
        #         g=max if g==min else min
        #     return f(a)
        # return f(nums)
        # n=len(nums)
        
        # while n>1:
        #     newNums=[0]*(n//2)
        #     for i in range(n//2):
        #         if i&1: #even number
        #             newNums[i]=max(nums[2*i],nums[2*i+1])
        #         else:
        #             newNums[i]=min(nums[2*i],nums[2*i+1])
        #     nums=newNums
        #     n=len(nums)
        # return nums[0]