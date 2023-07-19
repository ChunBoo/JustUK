from collections import defaultdict


class LRUCache:
    def __init__(self,capacity):
        self.capacity=capacity
        self.map=defaultdict(int)
        self.cache=[()]

    def get(self,key):
        if key in self.map:
            k,v=self.cache.pop()
            self.cache.insert(k,v)
            return node
        return -1

    def put(self,key,value):
        if key in self.map:
            node=self.cache.pop()
            self.cache.insert(node[0])
            return
        
        if len(self.cache)==self.capacity:
            node=self.cache.pop()
            self.map.pop(node)
        
        self.cache.insert(key,value)
        self.map[key]=value


lru=LRUCache(2)
lru.put(1,1)
lru.put(2,2)
print(lru.get(1))
