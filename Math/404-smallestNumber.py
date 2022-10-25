

def smallestNumber(n):
    if n==0:
        return 0
    
    if n<0:
        s=list(str(-n)).sort(reverse=True)
        return int("-"+"".join(s))
    else:
        s=list(str(n))
        s.sort()
        s=0
        for i in range(len(s)):
           if i!='0':
               s=i
        return int("".join(s[i]+s[:i]+s[i+1:])) 
    
    
n=310
print(smallestNumber(n))