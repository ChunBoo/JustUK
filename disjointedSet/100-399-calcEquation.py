
class DS:
    def __init__(self,n=0):
        self.distance=[1]*n
        self.parents=[i for i in range(n)]
        
    def merge(self, a,b,val):
        pa=self.find(a)
        pb=self.find(b)
        self.parents[pa]=pb
        self.distance[pa]=(self.distance[pb]*val)//self.distance[pa]
    def find(self, a):
        if a==self.parents[a]:
            return a
        root=self.find(self.parents[a])
        self.distance[a]*=self.distance[self.parents[a]]
        self.parents[a]=root
        return root
    
    def getDistance(self, a,b):
        pa=self.find(a)
        pb=self.find(b)
        if pa != pb:
            return -1
        return self.distance[a]/self.distance[b]


def calcEquation(equations,values, queries):
    d=dict()
    n=len(equations)
    ds=DS(n*2)
    # merge each nodes now
    idx=0
    for i in equations:
      if i[0] not in d: 
          d[i[0]] =idx
          idx+=1
      if i[1] not in d:
          d[i[1]]=idx
          idx+=1
    
    for i in range(n):
        ds.merge(d[equations[i][0]], d[equations[i][1]], values[i])
        
    ans=[]
    
    for  i in range(len(queries)):
        if queries[i][0] in d and queries[i][1] in d:
            ans.append(ds.getDistance(d[queries[i][0]], d[queries[i][1]]))    
        else:
            ans.append(-1)
    return ans


equations = [["a","b"],["b","c"]]
values = [2.0,3.0]
queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]

print(calcEquation(equations, values, queries))