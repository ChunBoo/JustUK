from itertools import product


def printCartesianProduct(A,B):
    c=list(product(A,B))
    return c

A=[1,2]
B=[3,4]

print(printCartesianProduct(A,B))

for k,i,j in product(range(1,3),repeat=3):
    print(k,i,j)