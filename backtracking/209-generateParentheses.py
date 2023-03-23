

def generateParentheses(n):
    ans=[]
    if n<1:
        return ans

    def dfs(cur,open,close):
        if len(cur)==n*2:
            if open==close:
                ans.append(cur)
                return
        
        if open<n:
            dfs(cur+'(',open+1,close)
        if close<open:
            dfs(cur+')',open,close+1)
    dfs("",0,0)
    return ans

print(generateParentheses(3))