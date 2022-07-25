
def foo(nums,L,R):
    def f(upperBound):
        cur=ans=0
        for i in nums:
            if i<=upperBound:
                cur+=1
            else:
                cur=0
            ans+=cur
        return ans
    h=f(R)
    l=f(L-1)
    return f(R)-f(L-1)


def f(nums,L,R):
    ans=0
    n=len(nums)
    for i in range(n):
        for j in range(i,n):
            s=nums[i:j+1]
            if L<=max(s) and R>=max(s):
                print(s)
                ans+=1
    return ans


nums=[0,1,5,3,4]
print(f(nums,3,4))
print("----------")
print(foo(nums,3,4))