def sumOfThree(n):
    if n==0:
        return [-1,0,1]
    mid=n//3
    ans=[mid-1,mid,mid+1]
    if sum(ans)==n:
        return ans
    return []