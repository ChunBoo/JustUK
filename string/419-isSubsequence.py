

class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s)>len(t):
            return False
        i,j=0,0
        while(i<len(s) and j<len(t)):
            if s[i]==t[j]:
                i+=1
                j+=1
            j+=1
    
        return i==len(s)
s="acb"
t="ahbgdc"    
# s="aaaaaa"
# t="bbaaaa"    
# s="abc"
# t="ahbgdc"
ss=Solution()
print(ss.isSubsequence(s,t))