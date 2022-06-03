def getXValue():
    pass
def maxAera(length):
    area=0
    h=8 # -b/(2*a)
    w=length-2*h
    return h*w

def bruteForceMethod(length):
    maxh=1
    area=0
    for h in range(1,length//2):
        if (length-2*h)*h>area:
            area=(length-2*h)*h
            maxh=h
    return area
    
print(maxAera(32)) 
print(bruteForceMethod(32))
    