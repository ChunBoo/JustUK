#top2bottom

rList=[]
nums=[1,2,3,4]
def f(n):
    if(n<0):
        return 0
    if(n==0):
        rList.append(9)
        return 1
    ans=0

    for v in nums:
        rList.append(v)
        ans+=f(n-v)
    return ans

# res=f(4)
# print(res)


def f2(nums,T):
    n=len(nums)
    dp=[0]*(T+1)
    dp[0]=1
    for i in range(1,T+1):
        for j in nums:
                if i>=j:
                    dp[i]+=dp[i-j]
    return dp[T]


res=f2([1,2,3,4],4)
print(res)

# for i in rList:
#     if i==9:
#         print('\n')
#     else:
#         print(i)
# print(rList)