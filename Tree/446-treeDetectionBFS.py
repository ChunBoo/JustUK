

from collections import defaultdict,deque

def treeDetection(left,right):
    n=len(left)
    data=defaultdict(int)
    for i in range(n):
        if left[i]!=-1:
            data[left[i]]+=1
        if right[i]!=-1:
            data[right[i]]+=1
    root=[i for i in range(n) if data[i]==0]
    if len(root)!=1:
        return False
    
    q=deque([root[0]])
    seen=set()
    while q:
        cur=q.popleft()
        if cur in seen:
            return False #there is cycle
        seen.add(cur)
        if left[cur]!=-1:
            q.append(left[cur])
        if right[cur]!=-1:
            q.append(right[cur])
    
    return len(seen)==n

left = [1, -1, 3, -1]
right = [2, -1, 4, -1]
print(treeDetection(left,right))