def  runLength(s):
    c=0
    ans=[]
    
    for i in s:
        if i.isdigit():
            c=c*10+int(i)
        else:
            ans.append(c)
            ans.append(i)
            c=0
            
    return "".join(ans[i]*ans[i+1] for i in range(0,len(ans),2))


s="2a3b4c5d6e"

print(runLength(s))