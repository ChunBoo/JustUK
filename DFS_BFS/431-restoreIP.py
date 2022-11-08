
def restoreIP(s):
    if len(s)>12 or len(s)<4:
        return []
    ans=[]
    def dfs(cur):
        n=sum(len(x) for x in cur)
        if len(cur)==4:
            if n==len(s):
                ans.append(".".join(cur))
        
            return 
        
        for i in range(n,min(n+3,len(s))):
            x=s[n:i+1]
            if 0<=int(x)<=255 and (x=='0' or (len(x)>0 and x[0]!='0')):
                cur.append(x)
                dfs(cur)
                cur.pop()
    
    dfs([])
    return ans

s="12345"
print(restoreIP(s))
