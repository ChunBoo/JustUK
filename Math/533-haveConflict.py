class Solution:
    def haveConflict(self, event1, event2):
        a1,a2=event1
        b1,b2=event2
        return max(a1,b1)<=min(a2,b2)
        # endTime1H,endTime1M=event1[-1].split(":")
        # sTime1H,sTime1M=event1[0].split(":")
        # sTime2H,sTime2M=event2[0].split(":")
        # endTime2H,endTime2M=event2[-1].split(":")
        # if sTime2H<endTime1H:
        #     return True
        # elif sTime2H==endTime1H and sTime2M<=endTime1M:
        #     return True
        # if endTime2H>sTime1H:
        #     return True
        # elif endTime2H==sTime1H and endTime2M<=sTime1M:
        #     return True
        # # elif sTime2H==endTime1H an
        # return False
        
        
time1=["02:00","04:00"]
time2=["04:10","05:00"]
print(Solution().haveConflict(time1, time2))