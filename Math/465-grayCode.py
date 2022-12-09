

def grayCode(n):
    if n==1:
        return [0,1]
    prev=grayCode(n-1)
    k=1<<(n-1)
    return prev+[k+x for x in prev[::-1]]

print(grayCode(2))