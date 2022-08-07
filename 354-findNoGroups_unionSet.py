

class UnionFind:
    def __init__(self) -> None:
        self.sizes={}
        self.parent={}
        
    def find(self,a):
        if a in self.parent:
            return self.parent[a]
        
        if a not in self.parent:
            self.parent[a]=a
            self.sizes[a]=1
            return a
        
        if self.parent[a]!=a:
            self.parent[a]=self.find(self.parent[a])
        
        return self.parent[a]
    
    
    def union(self,a,b):
        x=self.find(a)
        y=self.find(b)
        
        if x==y:
            return False
        
        if self.sizes[x]<self.sizes[y]:
            x,y=y,x
            
        self.parent[y]=x
        self.sizes[x]+=self.sizes[y]
        return True
    
    @property
    def  count(self):
        return sum([x==y for x,y in self.parent.items()])
    
    
def  geneMutationGroups(genes):
    g=set(genes)
    uf=UnionFind()
    
    for i in g:
        for j in range(len(i)):
            for k in ("A","G","C","T"):
                n=i[:j]+k+i[j+1:]
                if n in g:
                    uf.union(i,n)
                
    return uf.count


genes = ["ACGT", "ACCT", "AGGT", "TTTT", "TTTG"]
print(geneMutationGroups(genes))    