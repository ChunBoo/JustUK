

def isconsecutiveArray(nums):
    data=sorted(nums)
    nums.sort()
0    for i in range(0,len(data)-1):
        if data[i+1]-data[i]!=1:
            return False
    return True


nums=[2,6,3,5]
print(isconsecutiveArray(nums))