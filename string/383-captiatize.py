def captitize(s):
    words=s.split()
    for i ,w in enumerate(words):
        if len(w)<=2:
            words[i]=words[i].lower()
        else:
            words[i]=words[i].title()
    return " ".join(words)

def twoPointers(s):
    w=list(s)
    n=len(s)
    
    i=0
    j=0
    
    while(i<=n):
        if i==n or s[i]==' ':
            if i-j>2:
                w[j]=w[j].upper();
            j=i+1;
        else:
            w[i]=w[i].lower()
        i+=1
            
    return "".join(w) 


s="eRIC IS rYANS GOOD FRIEND"
print(twoPointers(s))