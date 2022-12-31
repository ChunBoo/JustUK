
from collections import Counter

def rearrangeChars(s,target):
    S=Counter(s)
    T=Counter(target)
    return min(S[i]//T[i] for i in T)


s = "ilovecodingonleetcode";target = "code"
print(rearrangeChars(s,target))