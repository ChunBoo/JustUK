class Solution:
    def countTime(self, time: str) -> int:
        ans=1
        if time[-1]=="?":
            ans*=10
        if time[-2]=="?":
            ans*=6
        if time[:2]=="??":
            ans*=24
        else:
            if time[0]=="?":
                if time[1]>="4" and time[1]<="9":
                    ans*=2
                elif time[1]<"4":
                    ans*=3
            elif time[1]=="?":
                if time[0]<"2":
                    ans*=10
                else:
                    ans*=4
        return ans
    
    def countTime2(self, time: str) -> int:
        ans = 1
        if time[4] == '?':
            ans *= 10
        if time[3] == '?':
            ans *= 6
        if time[0] == '?' and time[1] == '?':
            ans *= 24
        else:
            if time[0] == '?':
                if time[1] <= '3':
                    ans *= 3
                else:
                    ans *= 2
            if time[1] == '?':
                if time[0] <= '1':
                    ans *= 10
                else:
                    ans *= 4
        return ans