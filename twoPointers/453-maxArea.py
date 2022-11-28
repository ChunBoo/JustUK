
class Solution:
    def solution(self,heights):
        n=len(heights)
        l,r=0,n-1
        ans=0
        while l<r:
            ans=max(ans,min(heights[l],heights[r])*(r-l))
            if heights[l]<heights[r]:
                l+=1
            else:
                r-=1
        return ans
    
height = [1,8,6,2,5,4,8,3,7]
print(Solution().solution(height))