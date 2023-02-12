

def maxIncSubArraySum(arr):
    n=len(arr)
    ans=0
    cur=arr[0]
    for i in range(1,n):
        if arr[i]>arr[i-1]:
            cur+=arr[i]

        else:
            cur=arr[i]
        ans=max(ans,cur)
    return ans
arr=[10,20,30,5,10,50]
print(maxIncSubArraySum(arr))