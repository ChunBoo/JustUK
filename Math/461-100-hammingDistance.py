def hammingDistance(x,y):
    x^=y
    ans=0
    while(x):
        ans+=1
        x>>=1
    return ans

x=12
y=3
print(hammingDistance(x, y))