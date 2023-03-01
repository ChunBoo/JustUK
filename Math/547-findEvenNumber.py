from collections import Counter
class Solution:
    def findEvenNumbers(self, digits):
        c=Counter(digits)
        ans=[]
        for n in range(100,999,2):
            if n&1==0:
                cur=[int(i) for i in str(n)]
                isAllInDigits=True;
                tStr=Counter(cur)
                for k,v in tStr.items():
                    if v>c[k]:
                        isAllInDigits=False
                        continue
                if isAllInDigits:
                    ans.append(n)
        return ans
    def findEvenNumbers2(self, digits):
        C=Counter(digits)
        ans=[]
        for n in range(100,999,2):
            a=n//100
            b=(n//10)%10
            c=n%10
            if Counter((a,b,c))<=C:
                ans.append(n)
        return ans
nums=[2,1,3,0]
print(Solution().findEvenNumbers(nums))