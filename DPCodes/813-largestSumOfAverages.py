

def largestSumOfAverages(nums,K):
    n=len(nums)
    
    sum=[0]*(n+1)
    
    for i in range(1,n+1):
        sum[i]=nums[i-1]+sum[i-1]
        
    dp=[[0]*(K+1)]*(n+1)
    
    for i in range(1,n+1):
        dp[i][1]=sum[i]/i
    
    for i in range(1,n+1):
        for k in range(2,K+1):
            for j in range(1,i):
                dp[i][k]=max(dp[i][k],dp[j][k-1]+((sum[i]-sum[j])/(i-j)))
    
    return dp[n][K]

nums = [9,1,2,3,9]
k = 3

print(largestSumOfAverages(nums,k))