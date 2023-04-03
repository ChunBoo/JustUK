class Solution:
    def merge(self, intervals):
        n=len(intervals)
        if n==1:
            return intervals
        ans=[]
        intervals.sort(key=lambda x:x[0])  #sorted(intervals,key=lambda x:[0]) can not work
        left=intervals[0][0]
        right=intervals[0][1]
        for i in range(1,n):
            if right>=intervals[i][0]:
                right=max(right,intervals[i][1])
            else:
                ans.append([left,right])
                left=intervals[i][0]
                right=intervals[i][1]
    
        ans.append([left,right])
        return ans
    
intervals=[[1,4],[0,4]]#[[1,3],[2,6],[8,10],[15,18]]
print(Solution().merge(intervals))