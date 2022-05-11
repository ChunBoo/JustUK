

from collections import deque


def bfs4DAGtaget(G):
    n=len(G)-1
    ans=[]
    q=deque([(0,[0])])
    while q:
        curNode,curPath=q.popleft()
        if(curNode==n):
            ans.append(curPath)
        for nextNode in G[curNode]:
            q.append([nextNode,curPath+[nextNode]])
    
    return ans


G={0:[1,3],1:[2,3],2:[3],3:[]}
print(bfs4DAGtaget(G))