import math
w=[1,2,3]
v=[1,5,3]
# ans=-math.inf
def dfs(i,c):
    if i==len(w):
        return 0
    ans=0
    if c>=w[i]:
        ans=max(ans,dfs(i+1,c-w[i])+v[i])
        ans=max(ans,dfs(i+1,c))
    return ans

print(dfs(0,5))
