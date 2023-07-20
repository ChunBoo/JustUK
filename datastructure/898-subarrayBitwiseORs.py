
def subarrayBitwiseORs(nums):
    nxt,cur,ans=set(),set(),set()

    for v in nums:
        nxt.clear()
        nxt.add(v)
        for b in cur:
            nxt.add(b|v)
        cur=nxt
    
        ans.add(i for i in nxt)
    return len(ans)


nums=[1,3,2]
print(subarrayBitwiseORs(nums))
