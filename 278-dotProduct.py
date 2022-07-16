#used zip()
def dotProduct(a,b):
    n=len(a)
    assert(n==len(b))
    return sum(x[0]*x[1]  for x in zip(a,b))

a=[1,2,3]
b=[4,5,6]
print(dotProduct(a,b))