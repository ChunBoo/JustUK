from collections import Counter
class Solution:
    def minSetSize(self, arr):
        n=len(arr)
        d=Counter(arr)
        a=[y for x,y in d.items()]
        a.sort(reverse=True)   #O(NLogN)
        ans=0
        t=0
        for i in a:
            t+=i
            ans+=1
            if t+t>=n:
                return ans
            
            
arr = [3,3,3,3,5,5,5,2,2,7]
print(Solution().minSetSize(arr))