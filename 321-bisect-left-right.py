
#given one array,likes [1,2,2,3,3,3,4,4,5], bisect_left(array,3) will return the index of 3


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
arr=[1,2,2,3,3,3,4,4,5]
print(bisec_right(arr, 0))