def factor(n):
    if n==0 or n==1:
        return 1
    return n*factor(n-1)


def solve():
    x=0
    while True:
        if (x+20)==factor(x):
            return x+1
        else:
            x+=1
    
    
print(solve())