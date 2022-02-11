


def  getBuildings(nums):
    if nums is None:
        return []
    
    ans=[nums[0]]
    for i,h in enumerate(nums):
        while(ans and nums[ans[-1]]<=h):
            ans.pop(-1)
        ans.append(i)

    return ans


nums=[3,4,4,2,1]
res=getBuildings(nums)
print([nums[x] for x in res])
