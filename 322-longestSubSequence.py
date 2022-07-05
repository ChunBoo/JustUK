from bisect import bisect_left

def LIS(arr):
    if not arr:
        return 0
    n=len(arr)
    dp=[1]*n
    for i in range(n):
        for j in range(i):
            if arr[i]>arr[j]:
                dp[i]=max(dp[i],dp[j]+1)
    print(dp)
    return max(dp)


def greedyLIS(arr):
    lis=[]
    for i in arr:
        x=bisect_left(lis,i)
        if x==len(lis):  #current val is larger than all elements in lis
            lis.append(i)
        else:            #current val is smaller than lis[x]
            lis[x]=i
    print(lis)
    return len(lis)
arr=[3,2,4,1,7,6,10]
print(LIS(arr))
print(greedyLIS(arr))