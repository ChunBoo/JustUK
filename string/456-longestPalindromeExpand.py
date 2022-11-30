



def longestPalindrome(s):
    n=len(s)
    
    def expand(l,r):
        if l>=0 and r<n and s[l]==s[r]:
            l-=1
            r+=1
        return (l+1,r-1)
    L,R=0,-1
    # a,b,=0,0
    for i in range(n):
        a,b=expand(i,i)
        if b-a>R-L:
            L=a
            R=b
        a,b=expand(i,i+1)
        if b-a>R-L:
            L=a
            R=b
    return s[L:R+1]

s="abbccccbbaef"
print(longestPalindrome(s))