
from collections import Counter

def rearrangeChars(s,target):
    S=Counter(s)
    T=Counter(target)
    return min(S[i]//T[i] for i in T)

def rearrangeCharacters(s,target):
    S=Counter(s)
    ans=0
    while True:
        for i in target:
            if S[i]>0:
                S[i]-=1
            else:
                return ans
        ans+=1
    return 0

s = "ilovecodingonleetcode";target = "code"
print(rearrangeChars(s,target))
print(rearrangeCharacters(s,target))