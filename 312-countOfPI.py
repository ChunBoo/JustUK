

from random import random


def myPi(n):
    inside=0
    
    for _ in range(n):
        x=random()
        y=random()
        if x**2+y**2<=1:
            inside+=1
            
    return 4*inside/n

print(myPi(9000000))