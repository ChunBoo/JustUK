from math import inf
def splitArray(nums,k): #split the array as k groups with minimum sum 
    n=len(nums)
    m_sum=[0]*n
    m_mem=[[inf]*(k+1)]*n
    m_sum[0]=nums[0]
    for i in range(1,n):
        m_sum[i]=nums[i]+m_sum[i-1]
    
    def foo(m,k): #m is the groups, k is the count of numbers
        if m==1:
            return m_sum[k]
        if m>=k:
            return inf
        if m_mem[k][m]!=inf:
            return m_mem[k][m]
        ans=inf
        for i in range(k):
            ans=min(ans,max(m_sum[k]-m_sum[i], foo(m-1,i)))
        m_mem[k][m]=ans
        return ans
    foo(k,n-1)
    return m_mem[n-1][k]


nums = [7,2,5,10,8]
k = 2
print(splitArray(nums, k))