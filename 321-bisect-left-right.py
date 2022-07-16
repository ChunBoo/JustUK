
#given one array,likes [1,2,2,3,3,3,4,4,5], bisect_left(array,3) will return the index of 3

#The purpose of Bisect algorithm is to find a position in list where an element needs to be inserted to keep the list sorted.

#Python in its definition provides the bisect algorithms using the module “bisect” which allows to keep the list 
# in sorted order after insertion of each element. 
# This is essential as this reduces overhead time required to sort the list again and again 
# after insertion of each element.

"""
bisect_left(list, num, beg, end) :- This function returns the position in the sorted list, 
        where the number passed in argument can be placed so as to maintain the resultant list in sorted order. 
        If the element is already present in the list, the left most position where element has to be inserted is returned.
        This function takes 4 arguments, list which has to be worked with, 
        number to insert, starting position in list to consider, ending position which has to be considered.
"""
def bisec_left(arr,x):
    for i in range(len(arr)):
        if arr[i]>=x:
            return i
    return len(arr)



def bisec_right(arr,x):
    for i in range(len(arr)):
        if arr[i]>x:
            return i
    return len(arr)

def bisect_right(a,x,lo=0,hi=None):
    if lo<0:
        raise ValueError("Wrong Value of lo\n")
    if hi is None:
        hi=len(a)
    while lo<hi:
        mid=(lo+hi)//2
        if a[mid]>x:
            hi=mid
        else:
            lo=mid+1
    return lo

def bisect_left(a,x,lo=0,hi=None):
    if lo<0:
        raise ValueError("Wrong Value of lo.\n")
    if hi is None:
        hi=len(a)
    while lo<hi:
        mid=(lo+hi)//2
        if a[mid]>=x:
            hi=mid
        else:
            lo=mid+1
    return lo
    
arr=[1,2,2,3,3,3,4,4,5]
# print(bisec_right(arr, 0))
print(bisect_right(arr, 3,0,6))  #return the right-most pos 
print(bisect_left(arr, 3,0,1))   #return the left-most position