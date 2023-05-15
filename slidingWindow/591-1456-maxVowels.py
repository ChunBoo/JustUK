

def maxVowels(s,k):
    vowels=set("aeiou")
    win=0
    
    for i in range(k):
        win+=s[i] in vowels
    
    ans=win
    for i in range(k,len(s)):
        win+=s[i] in vowels
        win-=s[i-k] in vowels
        ans=max(ans,win)
    return ans


s = "abciiidef"
k = 3
print(maxVowels(s, k))