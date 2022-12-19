

#use hash table to store the intermediate values
def dp_bottom2Top(n):
    f0,f1=0,1
    for _ in range(n):
        f0,f1=f1,f0+f1
    return f0   #here is not return f1
    

def f_recurssion(n):
    if n==0 or n==1:
        return n
    return f(n-1)+f(n-2)

def f(n,nb={}):  #this is top2bottom method, f(n) should calculate the f(n-1) until f(0)
    if n==0 or n==1:
        return n
    if n in nb:
        return nb[n]
    val=f(n-1)+f(n-2)
    nb[n]=val
    return val


print(f(6))
print(dp_bottom2Top(6))
