class Solution:
    def minimumSum(self, num: int) -> int:
        s=str(num)
        y=sorted(s)
        n1=int(y[0]+y[3])
        n2=int(y[1]+y[2])
        return n1+n2