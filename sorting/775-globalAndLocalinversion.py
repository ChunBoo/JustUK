
def globalAndLocalinversion(nums):
    n=len(nums)
    local=0
    for i in range(n-1):
        if nums[i]>nums[i+1]:
            local+=1
    globals=mergeSort(nums,0,n-1)
    return globals==local
def mergeSort(nums,l,r):
    if l>=r:
        return 0

    len=r-l+1
    m=l+(r-l)//2
    inv=mergeSort(nums,l,m)+mergeSort(nums,m+1,r)
    tmp=[0]*(len+1)
    i,j,k=l,m+1,0
    while i<=m and j<=r:
        if nums[i]<nums[j]:
            tmp[k] = nums[i]
            k+=1
            i+=1
        else:
            tmp[k]=nums[j]
            inv+=len-i+1
            k+=1
            j+=1
    while i<=m:
        tmp[k]=nums[i]
        k+=1
        i+=1
    while j<=r:
        tmp[k]=nums[j]
        k+=1
        j+=1
    
    for ii in range(l,l+len):
        nums[ii]=tmp[ii-l]
    return inv

nums=[2, 1, 0]



print(globalAndLocalinversion(nums))