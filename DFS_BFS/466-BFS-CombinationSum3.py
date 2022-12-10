from collections import deque
def combinationSum(k,n):
    if k>9 or n>45:
        return []
    ans=[]
    q=deque([([],0,1)])
    while q:
        sz=len(q)
        for _ in range(sz):
            cur,s,x=q.popleft()
            if s==n and len(cur)==k:
                ans.append(cur[:])
            elif len(cur)<k and s<n:
                for i in range(x,10):
                    q.append([cur+[i],s+i,i+1])
    return ans

print(combinationSum(3,9))