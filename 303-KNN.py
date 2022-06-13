

def knn(x,data,n=3):
    assert n>=3
    cost=[(i,abs(i-x)) for i in data]
    
    cost.sort(key=lambda x:x[1])
    
    return sum(data[x[0]] for x in cost[:n])//n
data={}
for i in range(-100,101):
    data[i]=i**2
    
print(knn(3,data,3))
    
    