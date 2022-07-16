'''
   sliding windows example: used slide window to get the longest substring which has at most two unique chars
'''
from collections import defaultdict
def longest(s):
    n=len(s)
    ans,L,R=0,0,0
    win=defaultdict(int)
    while(R<n):
        win[s[R]]+=1
        while(L<=R and len(win.keys())>2):#update the sliding window now
            win[s[L]]-=1
            if(win[s[L]]==0):
                del win[s[L]]
            L+=1
        ans=max(ans,R-L+1)
        R+=1
    return ans

s="abccbb"
print(longest(s))