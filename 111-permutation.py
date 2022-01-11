
import copy 

def perm(nums):
    ans=[]
    def help(cur):
        if cur==len(nums):
            ans.append(copy.deepcopy(nums))
            return
        for i in range(cur,len(nums)):
            nums[i],nums[cur]=nums[cur],nums[i]
            help(cur+1)
            nums[i],nums[cur]=nums[cur],nums[i]
    help(0)
    return ans

nums=[1,2,3]
print(perm(nums))