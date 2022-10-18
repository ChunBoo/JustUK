
from collections import deque


class Node(object):
    def __init__(self,val,neighbors) -> None:
        self.val=val
        self.neighbors=neighbors
    def printout(self):
        for i in self.neighbors:
            print(i.val)  

class Solution(object):
    def cloneGraph(self,node):
        if not node:
            return node
        q=deque([node])
        seen={}
        seen[node]=Node(node.val,[])
        while q:
            cur=q.popleft()
            for n in cur.neighbors:
                if n not in seen:
                    seen[n]=Node(n.val,[])
                    q.append(n)
                seen[cur].neighbors.append(seen[n])
        return seen[node]
    
    
_one=Node(1,[])
_two=Node(2,[])
_three=Node(3,[])
_four=Node(4,[])
one=Node(1,[_two,_four])
two=Node(2,[_one,_three])
three=Node(3,[_two,_four])
four=Node(4,[_one,_three])


s=Solution()
ret=s.cloneGraph(one)
ret.printout()