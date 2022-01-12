class Trie:
    def __init__(self):
        self.data={}
        self.leaf=False
    def insert(self,word):
        cur=self
        for i in word:
            if i not in cur.data:
                cur.data[i]=Trie()
                cur=cur.data[i]
        cur.leaf=True
    
    def search(self,word):
        cur=self
        for i in word:
            if i not in cur.data:
                return False
            cur=cur.data[i]
        return True


words=["Eric","Ryan","Mum","Daddy"]
preWords=["Er","Dd"]

trie=Trie()
for w in words:
  trie.insert(w)

ans =0
for p in preWords:
   if trie.search(p):
       ans+=1
print(ans)
