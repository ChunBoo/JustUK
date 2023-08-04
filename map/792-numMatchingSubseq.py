
from bisect import bisect_left
from collections import defaultdict
def numMatchingSubseq(s,words):
    
    pos=[[0]*128]*128
    m=dict()
    def isMatch(w,pos):
        if w in m:
            return m[w]
        lastIndex=-1
        for c in w:
            p=pos[ord(c)]
            it=bisect_left(p,lastIndex+1,len(p))
            if it==len(p):
                m[w]=False
                return False
            lastIndex=it
        return True
            



    for i in range(len(s)):
        pos[ord(s[i])].append(i)
    ans=0
    for w in words:
        ans+=isMatch(w,pos)
    return ans

s = "abcde"
words=["a", "bb", "acd", "ace"]
print(numMatchingSubseq(s,words))
