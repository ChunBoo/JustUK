

def threeSum(nums):
    nums.sort()
    n=len(nums)
    ans=[]
    for i in range(n):
        if nums[i]>0:
            break
        if i>0 and nums[i]==nums[i-1]:
            continue
        
        l,r=i+1,n-1
        
        while(l<r):
            s=nums[i]+nums[l]+nums[r]
            if s==0:
                ans.append([nums[i],nums[l],nums[r]])
                while l<r and nums[l]==nums[l+1]: l+=1
                while l<r and nums[r]==nums[r-1]: r-=1
                l+=1
                r-=1
            elif s>0:
                r-=1
            else:
                l+=1
    return ans

nums=[-1,0,1,2,-1,-4]
print(threeSum(nums))