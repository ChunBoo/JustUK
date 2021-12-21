#给定一个整数，计算它的平方根，带有小数

def seqtWithFloat(n,a,E=1e-8):
    b=n-a**2
    x=a+b/a
    t=x
    while(n-x**2>E):
        x=a+b/t
        t=x
    return x


n=150.0
a=12.0
print(seqtWithFloat(n,12))