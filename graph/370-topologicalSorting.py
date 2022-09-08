

from collections import defaultdict, deque
from re import S

class Node(object):
    def __init__(self) -> None:
        self.inDegree=0
        self.outNodes=[]
        
class Solution(object):
    def solve(self,courses,numCourses):
        graph=defaultdict(Node)
        totalDeps=0
        for a,b in (courses):
            graph[a].inDegree+=1
            graph[b].outNodes.append(a)
            totalDeps+=1
        
        q=deque()
        for a,node in graph.items():
            if node.inDegree==0:
                q.append(a)
                
        r=0
        while q:
            v=q.popleft()
            for a in graph[v].outNodes:
                graph[a].inDegree-=1
                r+=1
                if graph[a].inDegree==0:
                    q.append(a)  
                    # r+=1
        return r==totalDeps
    
courses=[[1,0],[2,1]]
s=Solution()
res=s.solve(courses,3)
print(res)

     
                
# d=defaultdict(list)

# d[1]=[1,2]
# d[2]=[3,4]
# for k,v in d.items():
#     print(k,v)