
from bisect import bisect_left
from collections import defaultdict
def numMatchingSubseq(s,words):
    
    pos=[[0]]*128
    m=defaultdict(int)
    def isMatch(w,pos):
        if w in m:
            return m[w]
        lastIndex=-1
        for c in w:
            p=pos[c]
            it=bisect_left(p,lastIndex+1,len(p))
            if it
            



    for i in range(len(s)):
        pos[s[i]].append(i)