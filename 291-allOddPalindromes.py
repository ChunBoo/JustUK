

def  check(s):
    n=len(s)
    for i in range(1,n):
        if s[i]==s[i-1]:
            return False
    return True


s="racecar"
s1="noon"
print(check(s1))