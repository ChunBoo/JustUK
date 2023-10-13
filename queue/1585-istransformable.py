from collections import deque
def istransformable(s,t):
    idx=[deque() for _ in range(10)]
    kn=len(s)
    
    for i in range(kn):
        idx[ord(s[i])-ord('0')].append(i)
    
    for cc in t:
        d=ord(cc)-ord('0')
        if cc not in s:
            return False
        for i in range(d):
            if  len(idx[i])>0 and idx[i][0]<idx[d][0]:
                return False
        idx[d].popleft()
    return True
s = "845"
t = "485"
print(istransformable(s,t))