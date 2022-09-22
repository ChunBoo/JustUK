
from collections import Counter

def split2(s):
    if not s:
        return 0
    
    ans=0
    
    for i in range(len(s)):
        c1=Counter(s[:i+1])
        c2=Counter(s[i+1:])
        if len(c1)==len(c2):
            ans+=1
            print(s[:i+1],s[i+1:])
    return ans


def split2Faster(s):
    if not s:
        return 0
    
    ans=0
    
    for i in range(len(s)):
        c1=s[:i+1]
        c2=s[i+1:]
        if set(c1)==set(c2):
            ans+=1
            print(c1,c2)
            
    return ans

def split2Counter(s):
    if not s:
        return 0
    
    c1=Counter()
    c2=Counter(s)
    
    ans=0
    
    for i in range(len(s)-1):
        c1[s[i]]+=1
        c2[s[i]]-=1
        if c2[s[i]]==0:
            del c2[s[i]]
        
        if set(c1.keys())==set(c2.keys()):
            ans+=1
            print(c1,c2)
            
    return ans    
    
print(split2("aabab"))
print(split2Faster("aabaa"))
print(split2Counter("aabab"))