'''
 given a two-dimensional list of integers edges representing a connected, directed, 
 acyclic graph. Each element in edges contains [u, v] meaning there is an edge from u to v. 
 Return the minimum list of nodes from which we can visit every node in the graph, sorted in ascending order.
'''

from collections import defaultdict

def findNodes(edges):
    nodes=set()
    G=defaultdict(int)
    for a,b in edges.items():
        nodes.add(a)
        nodes.add(b)
        G[b]+=1
    ans=[]
    for n in nodes:
        if G[n]==0:
            ans.append(n)
    return ans


edges={'A':'B',"B":"C","D":"C"};
print(findNodes(edges))