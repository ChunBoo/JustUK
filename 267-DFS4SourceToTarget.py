#given the adjacent list for a DAG,to get all of the path from the source to target

def  allFromSrcToTarget(G):
    ans=[]
    def dfs(curPath,n):
        if n==len(G)-1:
            ans.append(curPath[:])
            return 
        for nextNode in G[n]:
            curPath.append(nextNode)
            dfs(curPath,nextNode)
            curPath.pop()
    dfs([0],0)
    return ans

G={0:[1,3],1:[2,3],2:[3],3:[]}
print(allFromSrcToTarget(G))