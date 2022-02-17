from itertools import accumulate
arr=[1,2,3,4,5]

a=accumulate(arr)
print(list(a))


def myAccumulate(a):
    for i in range(1,len(a)):
        a[i]+=a[i-1]
    yield from  a

r=myAccumulate(arr)
print(list(r))