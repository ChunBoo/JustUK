

def checkInclusion(s1,s2):
    l1,l2=len(s1),len(s2)

    c1,c2=[0]*26,[0]*26

    for c in s1:
        c1[ord(c)-ord('a')]+=1
    
    for i in range(l2):
        if i>=l1:
            c2[ord(s2[i-l1])-ord('a')]-=1
        c2[ord(s2[i])-ord('a')]+=1
        if c1==c2:
            return True
    return False


s1 = "ab"
s2 = "eidbaooo"
print(checkInclusion(s1,s2))