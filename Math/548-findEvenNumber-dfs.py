from collections import Counter

def findEvenNumbers(digits):
    ans=set()
    c=Counter(digits)
    def dfs(x):
        if x>99:
            if x&1==0:
                ans.add(x)
            return 
    
        for i in range(10):
            if c[i]>0:
                c[i]-=1
                dfs(x*10+i)
                c[i]+=1
    
    dfs(0)
    return sorted(ans)
nums=[2,1,3,0,0]
print(findEvenNumbers(nums))