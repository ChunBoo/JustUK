def runlengthCompressing(s):
    c=0;
    ans=""
    preChar=s[0]
    for i in s:
        if i=='e':
            print(i)
        if preChar==i:
            c+=1
        else:
            ans+=str(c)+preChar
            c=1
            preChar=i
    
    ans+=str(c)+s[-1]
    return ans

s="aabbbccccdddddeeeeee"
print(runlengthCompressing(s))