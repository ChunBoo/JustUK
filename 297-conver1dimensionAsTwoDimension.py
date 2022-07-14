#given  a list of integers, and the desired rows/cols for converting the list to two dimension array
def reshape(a,r,c):
    if len(a)!=r*c:
        return []
    ans=[[0 for _ in range(c)] for _ in range(r)]
    i=0;
    for rr in range(r):
        for cc in range(c):
            ans[rr][cc]=a[i]
            i+=1
    return ans
a=[1,3,5,7]
print(reshape(a,2,2))
i=1
# print(i+=1)