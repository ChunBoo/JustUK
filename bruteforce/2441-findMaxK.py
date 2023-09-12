
def findMaxK(nums):
	n=len(nums)
	ans=-1
	l,r=0,n-1
	nums.sort()

	while l<r:
		if nums[l]+nums[r]==0:
			return nums[r]
		elif nums[l]+nums[r]>0:
			r-=1
		else:
			l+=1
	return ans
nums=[1, 2, 3, 4, -7, -4, 7, 8]
print(findMaxK(nums))