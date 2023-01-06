

def longestSubString(s):
    n=len(s)
    l=r=0
    ans=0
    win=set()
    while r<n:
        while s[r] in win:
            win.remove(s[l])
            l+=1
        win.add(s[r])
        ans=max(ans,len(win))
        r+=1
    return ans

s="abcbbc"
print(longestSubString(s))