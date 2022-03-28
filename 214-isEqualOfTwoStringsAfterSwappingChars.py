
from collections import Counter

def isEqualAfterSwapping(s,t):
    c=Counter(s+t)
    for i in c.values():
       if i&1==1:
            return False
    return True


print(isEqualAfterSwapping("abcd","bade"))
