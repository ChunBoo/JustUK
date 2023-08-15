def letterCasepermutation(s):
    ans=[]
    n=len(s)
    def dfs(idx,S):
        if idx==n:
            ans.append(S)
            return 
        
        dfs(idx+1,S)
        if not S[idx].isalpha():
            return
        ll=list(S)
        ll[idx]=chr(ord(ll[idx])^(1<<5))
        S="".join(ll)
        dfs(idx+1,S)
        # s[idx]^=(1<<5)
        ll=list(S)
        ll[idx]=chr(ord(ll[idx])^(1<<5))
        S="".join(ll)

    dfs(0,s)
    return ans



        
s = "a1b2"
print(letterCasepermutation(s))