from bisect import bisect_left
class Solution:
    def getCommon(self, nums1, nums2) :
        l1=len(nums1)
        l2=len(nums2)
        if l1>l2:
            nums1,nums2=nums2,nums1
        for i in nums1:
            x=bisect_left(nums2,i)
            if x<len(nums2) and nums2[x]==i:
                return i
        return -1
        # i,j=0,0
        # n1=len(nums1)
        # n2=len(nums2)
        # while(i<n1 and j<n2):
        #     if nums1[i]==nums2[j]:
        #         return nums1[i]
        #     elif nums1[i]<nums2[j]:
        #         i+=1
        #     else:
        #         j+=1
        # return -1
        # s1=set(nums1)
        # s2=set(nums2)
        # s3=list(s1.intersection(s2))
        # # print(s3)
        # s3.sort()
        # return s3[0] if len(s3)>0 else -1
        
nums1 = [1,2,3,6]
nums2 = [2,3,4,5]
print(Solution().getCommon(nums1, nums2))