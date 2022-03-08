import math
def LCP(words):
    k=math.inf
    for w in words:
        k=min(k,len(w))
    i=0
    while(i<k):
        c=set(w[i] for w in words)
        if(len(c)!=1):
            break;
        i+=1
    return words[0][:i]

words=["won","words","world"]
print(LCP(words))