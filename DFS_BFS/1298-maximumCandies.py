import queue


def maxValues(status,candies,keys,containedBoxes,initialBoxes):
    found=[0]*len(status)
    hasKeys=keys[:]
    q=queue.Queue()
    for b in initialBoxes:
        if hasKeys[b]:
          q.append(b)
        found[b]=1
    ans=0
    while q:
        t =q.get()
        ans+=candies[t]
        for b in containedBoxes[b]:
            found[b]=1
            if hasKeys[b]:
                q.put(b)
        
        for t in keys[b]:
            if not hasKeys[t] and found[t]:
                q.put(t)
            hasKeys[t]=1
    return ans
        
        






status = [1,0,1,0]
candies = [7,5,4,100]
keys = [[],[],[1],[]]
containedBoxes = [[1,2],[3],[],[]]
initialBoxes = [0] 

print(maxValues(status,candies,keys,containedBoxes,initialBoxes))