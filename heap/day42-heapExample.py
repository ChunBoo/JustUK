import heapq as hq

def  foo(data):
    hq.heapify(data)
    hq.heappush(data,10)
    hq.heappush(data,1)
    
    m=hq.nlargest(2,data)
    n=hq.nsmallest(3,data)
    
    x=hq.heapreplace(data,200)
    print(m)
    print(n)
    print(data)
    
data=[3,100,20]

foo(data)