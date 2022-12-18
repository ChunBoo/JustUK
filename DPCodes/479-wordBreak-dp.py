

def wordBreak(s,wordsDict):
    w=set(wordsDict)
    n=len(s)
    dp=[False]*(n+1)
    dp[0]=True
    
    for i in range(1,n+1):
        for j in range(i):
            if s[j:i] in w and dp[j]:
                dp[i]=True
                break;
    return dp[-1]


s = "applepenapple"
w = ["apple","pen"]
print(wordBreak(s,w))