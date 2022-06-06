from logging import exception


class HashTable:
    def __init__(self):
        self.size=2
        self.data=[[] for i in range(self.size)]   
    
    def getKey(self,akey):
        return akey%self.size
    
    def getValue(self,aKey):
        key=self.getKey(aKey)
        for i in self.data[key]:
            if i[0]==akey:
                return i[1]
        return -1
    
    def update(self,akey,val):
        key=self.getKey(akey)
        for i in self.data[key]:
            if i[0]==akey:
                i[1]=val
                return 
        self.data[key].append((akey,val))
        
    def returnData(self):
        return self.data
              
    def remove(self,akey):
        key=self.getKey(akey)
        for i in range(len(self.data[key])):
            if  self.data[key][i][0]==akey:
                self.data[key][i]=self.data[key][-1][:]
                self.data[key].pop()
                return 
        raise  Exception("Not found the key:",akey)
        
ht=HashTable()  #here we should add the parenthesis
for i in range(9):
    ht.update(i,i)
'''
ht.update(1,2)
ht.update(2,3)
ht.update(3,4)
'''
# print(ht.getKey(8))
# # ht.remove(1)
# print(ht.get(1))
# print(ht.get(3))
ht.remove(12)
curData=ht.returnData()
print(curData)