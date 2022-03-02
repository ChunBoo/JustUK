def cartesianProduct(*a):
    def dfs(left,cur):
        if left==len(a):
            yield tuple(cur)
            return 
        for i in a[left]:
            yield from dfs(left+1,cur+[i])
    yield from dfs(0,[])


a=cartesianProduct([1,2],[3,4])
print(list(a))
