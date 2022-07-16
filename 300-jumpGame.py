#dfs


def jump(nums):
    n=len(nums)
    def dfs(cur):
        if cur>=n:
            return True   #can reach the end of the nums
        
        for i in range(1,min(n,nums[cur])):
            if dfs(i+cur):
                return True
        return False
    return dfs(0)


nums=[2,3,1,1,4]
print(jump(nums))