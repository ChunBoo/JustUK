

def removeDuplicated(a):
    b=list(sorted(set(a)))
    
    for i in range(len(b)):
        a[i]=b[i]
        
    return len(b)

def removeDuplicatedWithoutList(a):
    x=1;
    for i in range(1,len(a)):
        if a[i]!=a[i-1]:
            a[x]=a[i]
            x+=1
    return x
a=[1,2,2,3,4,4,5,6]
# print(removeDuplicated(a))
# print(a)
print("-----------")
print(removeDuplicatedWithoutList(a))
print(a)