


def  getBuildings(nums):
    ans=[]
    if(nums is None):
        return ans
    ans.append(nums[0])
    for i,v in enumerate(nums):
        while(ans and nums[ans[-1]]<=v):
            ans.pop(-1)
        ans.append(i)

    return ans


nums=[3,4,4,2,1]
res=getBuildings(nums)
print([nums[x] for x in res])
