
def longestSubstring(s):
    n=len(s)
    L=R=0
    ans=0
    win=set()
    d=dict()
    while R<n:
        x=s[R]
        i=d.get(x,-1)+1
        while L<i:
            win.remove(s[L])
            L+=1
        d[x]=R
        win.add(s[R])
        R+=1
        ans=max(ans,len(win))
    return ans

s="abcbbc"
print(longestSubstring(s))