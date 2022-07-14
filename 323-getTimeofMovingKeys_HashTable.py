#given a set of chars in our keyboard and one string which want to get the length
#used dictionary to record each chars index
def getTime(keys,s):
    d={}
    for i,c in enumerate(keys):
        d[c]=i
    ans=d[s[0]]
    
    for i in range(1,len(s)):
        ans+=abs(d[s[i]]-d[s[i-1]])
        
    return ans

keyboard = "abcdefghijklmnopqrstuvwxyz"
word = "cba"

print(getTime(keyboard,word))