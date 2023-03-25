

def permutation(nums):
    ans=[]
    
    def dfs(cur):
        if len(cur)==len(nums):
            ans.append(cur)
        
        for i in nums:
            if i in cur:
                continue
            dfs(cur+[i])
    dfs([])
    return ans

print(permutation([1,2,3]))