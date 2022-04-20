

def f(s,brokens):
    b=set(brokens)
    arr=s.split(" ")
    ans=0
    for s in arr:
        if all( i not in b for i in s):
            ans+=1

    return  ans


print(f("Tom likes playing","ok"))