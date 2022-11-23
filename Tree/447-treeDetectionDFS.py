

from collections import defaultdict
def treeDetection(left,right):
    n=len(left)
    data=defaultdict(int)
    for i in range(n):
        if left[i]!=-1:
            data[left[i]]+=1
        if right[i]!=-1:
            data[right[i]]+=1
            
    root=[x for x in range(n) if data[x]==0]
    if len(root)!=1:
        return False
    seen=set()
    def dfs(root):
        if root in seen:
            return False
        seen.add(root)
        if left[root]!=-1:
            if not dfs(left[root]):
                return False
        if right[root]!=-1:
            if not dfs(right[root]):
                return False
        return True
    return dfs(0) and n==len(seen)

left = [1, -1, 3, -1]
right = [2, -1, -1, -1]
print(treeDetection(left,right))