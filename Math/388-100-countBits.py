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

def countBITS(n):
    ans=[0]
    for i in range(1,n+1):
        if i&1:  #odd number
            ans.append(ans[i-1]+1)   # append its previous integer and add 1
        else:    # even number
            ans.append(ans[i//2])    #same count of 1 with it's half value
    return ans
        

print(countBits(5))
print(countBITS(5))