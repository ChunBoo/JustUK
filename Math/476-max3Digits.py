class Solution(object):
    def largestGoodInteger(self, num):
        """
        :type num: str
        :rtype: str
        """
        n=len(num)
        s=set()
        for i in range(n-2):
            if (str(num[i])*3)==str(num[i:i+3]):
                s.add(num[i])
        return str(max(s))*3 if s else ""
    def largestGoodInteger2(self,num):
        for i in range(9,-1,-1):
            a=str(i)*3
            if a in num:
                return a
        return ""
num="6777133339"#"3200014888"
print(Solution().largestGoodInteger(num))