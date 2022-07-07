

def removeDuplicated(a):
    b=list(sorted(set(a)))
    
    for i in range(len(b)):
        a[i]=b[i]
        
    return len(b)


a=[1,2,2,3,4,4,5,6]
print(removeDuplicated(a))
print(a)