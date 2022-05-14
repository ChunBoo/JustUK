class DisjointSet(object):
    def __init__(self,n) -> None:
        self.parent=list(range(n))
        self.GroupCnt=n
        
    def findParent(self,a): #compress the set
        pa=a
        while pa!=self.parent[a]:
            pa=self.parent[a] #not self.parent[pa]
        
        while(pa!=a):  #reset the parent node now
            t=self.parent[a]
            self.parent[a]=pa
            a=t
        return pa
    
    def sameGroup(self,x,y):
        return self.findParent(x)==self.findParent(y)
    
    def merge(self,x,y):
        groupX=self.findParent(x)
        groupY=self.findParent(y)
        if groupX==groupY:
            return 
        
        self.parent[y]=groupX
        self.GroupCnt-=1
    
    