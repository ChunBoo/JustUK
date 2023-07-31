class UnionFind:

    def __init__(self):
        self.parents=[]
        self.sizes=[]
    def redundantConnection(self,edges):
        self.parents=[0]*(len(edges)+1)
        self.sizes=[1]*(len(edges)+1)

        for e in edges:
            u,v=e[0],e[1]
            if self.parents[u]==0:
                self.parents[u]=u
            if self.parents[v]==0:
                self.parents[v]=v

            pu,pv=self.find(u),self.find(v)
            if pu==pv:
                return e
            if self.sizes[pu]<self.sizes[pv]:
                pu,pv=pv,pu
            
            self.parents[pv]=pu
            self.sizes[pu]+=self.sizes[pv]

        return []
    def find(self,cur):
        while cur!=self.parents[cur]:
            self.parents[cur]=self.parents[self.parents[cur]]
            cur=self.parents[cur]
        return cur

    


edges=[[1, 2], [2, 3], [1, 3]]
print(UnionFind().redundantConnection(edges))
