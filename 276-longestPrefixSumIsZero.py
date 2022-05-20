def  foo(nums):
    p={0:-1}
    ans,cur=0,0
    for i,n in enumerate(nums):
        cur+=n
        if(cur in p):
            ans=max(ans,i-p[cur])
        else:
            p[cur]=i
    return ans


nums=[1,0,1,-1,-2,0]
print(foo(nums))
            