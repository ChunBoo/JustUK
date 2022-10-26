

def isPrefix(p,s):
    if len(p)>len(s):
        return False
    i=0
    while(i<len(p)):
        if p[i]!=s[i]:
            return False
        i+=1
    return True

def isSuffix(p,s):
    if len(p)>len(s):
            return False
    ip,iss=len(p)-1,len(s)-1
    while(ip>=0):
        if p[ip]!=s[iss]:
            return False
        ip-=1
        iss-=1
    return True


p="abcdE"
s="abcdefgabcd"
print(isPrefix(p,s))
print(isSuffix(p,s))
    