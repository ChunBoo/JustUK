from math import sqrt

class solution:

    def __init__(self,nums):
        self.nums=nums
        n=len(nums)
        self.m=int(sqrt(n))
        
        self.blocks=[0]*self.m
        
        for i in range(n):
            self.blocks[i//self.m]+=nums[i]
            

    def updateBlocks(self,idx,val):
        self.blocks[idx//self.m]+=val-self.nums[idx]
        self.nums[idx]=val
    
    def  sumRange(self,i,j):
        ans=0
        p=i
        while p<=j:
            if (p%self.m ==0) and (p+self.m)<=j:
                ans+=self.blocks[p//self.m]
                p+=self.m
            else:
                ans+=self.nums[p]
                p+=1
        return ans


nums=[1,2,3,4,5,6,7,8,9]
s=solution(nums)
print(s.sumRange(1,3))
    