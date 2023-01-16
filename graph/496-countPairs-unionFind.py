
class DisjointSet(object):
    def __init__(self,n) -> None:
        self.par=list(range(n))
        self.size=[1]*n
        self.total=n
    
    def merge(self,a,b):
        a,b=self.find(a),self.find(b)
        if a==b:
            return False
        if self.size[a]<self.size[b]:
            a,b=b,a
        self.par[b]=a
        self.size[a]+=self.size[b]
        
        self.size[b]=0
        self.total-=1
        return True
    
    def find(self,a):
        if a !=self.par[a]:
            self.par[a]=self.find(self.par[a])
        return self.par[a]
    
    def getSize(self,a):
        return self.size[a]
    
    def count(self):
        return self.total
    
    
def countPair(n,edges):
    ds=DisjointSet(n)
    ans=0
    for a,b in edges:
        ds.merge(a,b)
    
    for i in range(n):
        c=ds.getSize(i)
        ans+=(n-c)*c
    return ans//2


n = 7
edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
print(countPair(n,edges))
    