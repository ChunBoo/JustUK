
def findDifference(nums1,nums2):
    s1,s2=set(nums1),set(nums2)
    n1,n2=len(s1),len(s2)
    
    return [list(s1-s2),list(s2-s1)]


nums1=[1,2,3]
nums2=[2,4,6]
print(findDifference(nums1,nums2))