class Solution:
    def maxProfitAssignment(self, difficulty, profit, worker):
        n=len(difficulty)
        jobs=[(0,0)]
        for i in range(n):
            # print(i)
            jobs.append((difficulty[i],profit[i]))
        
        jobs.sort()
        worker.sort()
        print(worker)
        ans=0
        i=1
        best=0
        # print(jobs)
        for level in worker:
            while i<=n and level>=jobs[i][0]:
                # print(i)
                best=max(best,jobs[i][-1])
                i+=1
            ans+=best
        return ans
class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        kN=100000   #can not use 1e5 HERE!!! if use this way, then next line will be failed
        maxProfit=[0]*(kN+1)

        for i in range(len(difficulty)):
            maxProfit[difficulty[i]]=max(maxProfit[difficulty[i]],profit[i])
        
        for i in range(2, kN+1):
            maxProfit[i]=max(maxProfit[i],maxProfit[i-1])

        ans=0
        for lvl in worker:
            ans+=maxProfit[lvl]
        return ans
diff,profit,worker=[13,37,58],[4,90,96],[34,73,45]
print(Solution().maxProfitAssignment(diff,profit,worker))