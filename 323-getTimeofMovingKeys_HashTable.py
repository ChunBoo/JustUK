

def getTime(keys,s):
    d={}
    for i,c in enumerate(keys):
        d[c]=i
    ans=d[keys[0]]
    
    for i in range(1,len(s)):
        ans+=abs(d[s[i]]-d[s[i-1]])
        
    return ans

keyboard = "abcdefghijklmnopqrstuvwxyz"
word = "cba"

print(getTime(keyboard,word))