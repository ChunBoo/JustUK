

def removeVowels(s):
    ans=""
    for i in s:
        if i not in "aeiou":
            ans+=i
    return ans

def removeVowels2(s):
    Vowels=set("aeiou")
    
    ans=[]
    for i in s:
        if i not in Vowels:
          ans.append(i)
          
    return "".join(ans) 

def removeVowels3(s):
    return "".join(filter(lambda x:x not in "aeiou",s))

def removeVowels4(s):
    return "".join([x for x in s if x not in "aeiou"])

print(removeVowels4("abcdie"))