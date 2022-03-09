
def check(s0,s1):
    if len(s0)-1!=len(s1):
        return False
    for i in range(len(s0)):
        if(s1[i]!=s0[i]):
            return s0[i+1:]==s1[i:]
        
        

print(check("abde","ade"))