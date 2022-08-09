"""_summary_
You are given a list of unique strings genes where each element has the same length and 
contains characters “A”, “C”, “G” and/or “T”.
If strings a and b are the same string except for one character, then a and b are in the same mutation group.
If strings a and b are in a group and b and c are in a group, then a and c are in the same group.
Return the total number of mutation groups.

Constraints
n ≤ 10,000
k ≤ 20 where k is the length of a string in genes
Example 1
Input
genes = [“ACGT”, “ACCT”, “AGGT”, “TTTT”, “TTTG”]
Output
2
Explanation
There are two mutation groups:
[“ACGT”, “ACCT”, “AGGT”]
[“TTTT”, “TTTG”]

Hint:
How can we connect one word with another? Is there a better way to connect than simply comparing each pair? After connecting words with each other, return the groups they form.

Human has 23 chromosomes (one of them controls the gender, where XX means girls and XY means boys). Each chromosome has hundreds of genes.

Returns:
    _type_: _description_
"""
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