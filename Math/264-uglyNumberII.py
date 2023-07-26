

def power2():
    i=1
    while i<2**31:
        yield i
        i*=2

def power3(n):
    i=n
    while i<2**31:
        yield i
        i*=3

def power5(n):
    i=n
    while i<2**31:
        yield i
        i*=5

def nthUglyNumber(n):
    nums=[]

    for a in power2():
        # print("a= ",a)
        for b in power3(a):
            # print("b= ",b)
            for c in power5(b):
                # print("c= ",c)
                nums.append(c)
    # nums.sort()
    newNums=sorted(nums)  #NOTE: sorted() return new list,original one keep it's seq
    # print(newNums)
    return newNums[n-1]


def nthUglyNumber2(n):
    nums=[1]
    i2,i3,i5=0,0,0
    while len(nums)<n:
        nxt2=nums[i2]*2
        nxt3=nums[i3]*3
        nxt5=nums[i5]*5
        next=min(nxt2,nxt3,nxt5)
        if next==nxt2:
            i2+=1
        if next==nxt3:
            i3+=1
        if next==nxt5:
            i5+=1
        nums.append(next)
    return nums[n-1]

print(nthUglyNumber(10))
print(nthUglyNumber2(10))