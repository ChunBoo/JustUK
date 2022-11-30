from functools import lru_cache

@lru_cache
def f(i,j,s):
    if i>j or i>=len(s) or j>=len(s):
        return 
    if i==j:
        return True
    if i+1==j:
        return s[i]==s[j]
    return s[i]==s[j] and f(i+1,j-1,s)

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