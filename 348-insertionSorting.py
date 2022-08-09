#simple insertion sorting algorithm

def insertionSorting(A):
    sz=len(A)
    if sz==0:
        return A
    for i in range(1,sz):
        key=A[i]
        j=i-1
        while j>=0 and key<A[j]:
            A[j+1]=A[j]
            j-=1
        
        A[j+1]=key  #j is -1 when is the smallest value
        
    return A


nums=[3,5,2,9,1,6];
newVals=insertionSorting(nums)
print(newVals)
