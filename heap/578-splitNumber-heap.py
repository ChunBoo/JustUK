from heapq import heapify,heappop

def splitNum(n):
    d=list(str(n))
    heapify(d)
    s1,s2=0,0
    while d:
        s1=s1*10+(int)(heappop(d))
        if d:
            s2=s2*10+int(heappop(d))
    return s1+s2

print(splitNum(1234))
        