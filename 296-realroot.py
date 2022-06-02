def findRealRoot(a,b,c):
    if a==0:
        raise Exception("a==0")
    if b**2-4*a*c<0:
        raise Exception("no real root")
    
    r=(b*b-4*a*c)**0.5
    x1=(-b+r)/(2*a)
    x2=(-b-r)/(2*a)
    
    return (x1,x2)


print(findRealRoot(1,-2,1))