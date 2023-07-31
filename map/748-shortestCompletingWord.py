from math import inf
def shortestCompletingWord(s,words):
    l=[0]*26

    for ch in s:
        if ch.isalpha():
            l[ord(ch.lower())-ord('a')]+=1
    
    def match(w):
        lch=[0]*26
        for c in w:
            lch[ord(c.lower())-ord('a')]+=1
        
        for i in range(0,26):
            if lch[i]<l[i]:
                return False
        return True
    minLen=inf
    ans=""
    for w in words:
        if len(w)>minLen:
            continue
        if not match(w):
            continue
        minLen=len(w)
        ans=w
    return ans


                
licensePlate = "1s3 PSt"
words = ["step","steps","stripe","stepple"]
print(shortestCompletingWord(licensePlate,words))