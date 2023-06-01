

from functools import cache
def canBreakWords(s,wordsDict):
    words=set(wordsDict)
    
    @cache
    def dp(s):
        if s in words:
            return True
        for i in range(min(20,len(s))):
            if s[:i] in words and dp(s[i:]):
                return True
        return False
    
    return dp(s)


s = "applepenapple"
w = ["apple","pen2"]
print(canBreakWords(s, w))