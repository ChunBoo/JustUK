
def isRotateStrings(s1,s2):
    m,n=len(s1),len(s2)
    if(m!=n):
        return False
    for i in range(m):
        s1=s1[1:]+s1[0]
        if(s1==s2):
            return True
    return False

def isRotatedStrings(s1,s2):
    return s2 in s1+s1

print(isRotatedStrings("abc","bca"))