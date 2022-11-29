
from collections import defaultdict

class DisjointSet(object):
    def __init__(self,n):
        self.par=list(range(n))
        self.count=n
        self.sz=[1]*n
    
    def union(self,a,b):
        pa=self.find(a)
        pb=self.find(b)
        if pa==pb:
            return False
        
        if self.sz[pa]<self.sz[pb]:
            pa,pb=pb,pa
        
        self.par[pb]=pa
        self.sz[pa]+=self.sz[pb]
        self.count-=1
        return True
    
    def find(self,a):
        if self.par[a]!=a:
            self.par[a]=self.find(self.par[a])
        return self.par[a]
    
    @property
    def size(self):
        return self.count
    
class Solution:
    def solve(self,left,right):
        n=len(left)
        ds=DisjointSet(n)
        ind=defaultdict(int)
        for i in range(n):
            #check there is no cycles
            if left[i]!=-1 and not ds.union(left[i],i):
                return False
            if right[i]!=-1 and not ds.union(right[i],i):
                return False
            #indegree checks, a node can have at most one indegree
            if left[i]!=-1:
                ind[left[i]]+=1
                if ind[left[i]]>1:
                    return False
            if right[i]!=-1:
                ind[right[i]]+=1
                if ind[right[i]]>1:
                    return False
        return ds.size==1
    
left = [1, -1, 3, -1]
right = [2, -1, -1, -1]
print(Solution().solve(left,right))
        