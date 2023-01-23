from itertools import product


def printCartesianProduct(A,B,C):
    c=list(product(A,B,C))
    return c

A=[1,2]
B=[3,4]
C=[5,6]
print(printCartesianProduct(A,B,C))

# for k,i,j in product(range(1,3),repeat=3):
    # print(k,i,j)