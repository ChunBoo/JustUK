from logging import exception


class HashTable:
    def __init__(self) -> None:
        self.size=65535
        self.data=[[] for _ in range(self.size)]
        
    def getKey(self,akey):
        return akey%self.size

    def get(self,akey):
        key=self.getKey(akey)
        for i in self.data[key]:
            if i[0]==akey:
                return i[1]
        return -1
    def update(self,akey,val):  # this key is in list,then update,or append it
        key=self.getKey(akey)
        for i in self.data[key]:
            if i[0]==akey:
                i[1]=val
                return
        
        self.data[key].append((akey,val))
    
    def remove(self,akey):
        key=self.getKey(akey)
        for i in range(len(self.data[key])):
            if len(self.data[i])>0 and self.data[i][0]==akey:
                self.data[key][i]=self.data[key][-1][:]
                self.data[key].pop()
                return 
        raise Exception("Not found the key!")
                
                
                

ht=HashTable()
ht.update(1,2)
print(ht.getKey(1))
ht.remove(1)
print(ht.get(1))