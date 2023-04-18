def cnt(n):
    ans=0
    while n:
        ans+=1
        n&=(n-1)
    return ans

def countBits(n):
    ans=[]
    for i in range(n):
        ans.append(cnt(i))
    return ans

print(countBits(5))