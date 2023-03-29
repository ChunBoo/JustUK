

def splitNum(n):
    s=str(n)
    b=[0]*10
    for c in s:
        b[int(c)]+=1
    
    s1,s2=0,0
    i=0
    while i<10:
        while i<10 and b[i]==0:
            i+=1
        if i==10:
            break
        s1=s1*10+i
        b[i]-=1
        while i<10 and b[i]==0:
            i+=1
        if i==10:
            break;
        s2=s2*10+i
        b[i]-=1
    return s1+s2

print(splitNum(12340))