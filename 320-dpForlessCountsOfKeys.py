

def f(n):
    if n<=1:
        return 0
    
    dp=list(range(n+1))
    for i in range(2,n+1):
        for j in range(2,i//2+1):
            if i %j==0:
                dp[i]=min(dp[i],dp[j]+i//j)
    return dp[-1]

def f2(n):
    if n<=1:
        return 0
    
    ans=n
    for i in range(2,n//2+1):
        if n%i==0:
            ans=min(ans,f(i)+n//i)
    return ans
print(f2(6))