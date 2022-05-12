#given the adjacent list for a DAG,to get all of the path from the source to target
#using the DFS method
def  allFromSrcToTarget(G):
    ans=[]
    n=len(G)-1
    def dfs(curNode,curPath):
        if curNode==n:
            ans.append(curPath[:])
            return 
        for nextNode in G[curNode]:
            curPath.append(nextNode)
            dfs(nextNode,curPath)
            curPath.pop()
    dfs(0,[0])
    return ans

G={0:[1,3],1:[2,3],2:[3],3:[]}
print(allFromSrcToTarget(G))