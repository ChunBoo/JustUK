class Solution:
    def minimumSum(self, num):
        s=str(num)
        y=sorted(s)
        n1=int(y[0]+y[3])
        n2=int(y[1]+y[2])
        return n1+n2
    
    def minimumSum2(self,num):
        nums=[]
        while num:
            rem=num%10
            nums.append(rem)
            num//=10;
        
        nums.sort()
        n1=nums[0]*10+nums[3]
        n2=nums[1]*10+nums[2]
        return n1+n2
    
n=1001
print(Solution().minimumSum2(n))