
def ThreeSum(nums,T):
    seen={}
    for i,v in enumerate(nums):
        seen[v]=i
        newT=T-v
        for j in range(i+1,len(nums)):
            if not newT - nums[j] in seen:
                seen[nums[j]]=j
            else:
                if not j==seen[newT-nums[j]]:
                    return [i,j,seen[newT-nums[j]]] 
    return [0,0,0]

def TwoSum(nums,T):
    seen={}
    for i,v in enumerate(nums):
        if not T-v in seen:
            seen[v]=i
        else:
            return [seen[T-v],i]
        
    return [0,0]

# res=TwoSum([1,2,3,4,5],5)
res2=ThreeSum([1,2,3,4,5],9)
print(res2)
# print(res)