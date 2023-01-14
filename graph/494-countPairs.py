from collections import Counter,defaultdict

def countPairs(n,edges):
    G=defaultdict(list)
    for a,b in edges:
        G[a].append(b)
        G[b].append(a)
    ans=0
    seen=set()
    def dfs(i):
        if i in seen:
            return 0
        seen.add(i)
        a=1
        for i in G[i]:
            a+=dfs(i)
        return a  #get all the nodes count in the same group
    for i in range(n):
        if i not in seen:
            c=dfs(i)
            ans+=c*(n-c)
    return ans//2

n = 7
edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
print(countPairs(n,edges))