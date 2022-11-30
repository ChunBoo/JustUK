from functools import lru_cache

@lru_cache
def f(i,j,s):   #top2bottom
    if i>j or i>=len(s) or j>=len(s):
        return 
    if i==j:
        return True
    if i+1==j:
        return s[i]==s[j]
    return s[i]==s[j] and f(i+1,j-1,s)
def longestPalindromeDP(s):
    n=len(s)
    F=[[True for _ in range(n)] for _ in range(n)]
    for i in range(n-2,-1,-1):
        for j in range(i,n):
            F[i][j]=s[i]==s[j] and F[i+1][j-1]
    L,R=0,0
    for i in range(n):
        for j in range(n-1,i-1,-1):
            if F[i][j]:
                if j-i>R-L:
                    L=i
                    R=j
                break;
    return s[L:R+1]
def longestPalindrome(s):
    n=len(s)
    L=R=-1
    for i in range(n):
        # for j in range(i+1,n):
        for j in range(n-1,i-1,-1):    
            c=s[i:j+1]
            # if c[::-1]==c:
            if f(i,j,c):
                if j-i>R-L:
                    L=i
                    R=j
                break
    return s[L:R+1]

s="abbccccbbaef"
print(longestPalindrome(s))
print(longestPalindromeDP(s))