

def letterCasepermutation(s):
    ans=[]
    n=len(s)
    def dfs(idx):
        if idx==n:
            ans.append(s)
            return 
        
        dfs(idx+1)
        if not s[idx].isalpha():
            return
        s[idx]=chr((ord(s[idx])^(1<<5)))
        dfs(idx+1)
        # s[idx]^=(1<<5)
        s[idx]=chr((ord(s[idx])^(1<<5)))

    dfs(0)
    return ans



        
s = "a1b2"
print(letterCasepermutation(s))