'''
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
'''

class Solution:
    def minInsertions(self, s: str) -> int:
        n=len(s)
        @lru_cache
        def dp(i,j):
            if i>=j:
                return 0
            
            return dp(i+1,j-1) if s[i]==s[j] else min(dp(i+1,j),dp(i,j-1))+1
        return dp(0,n-1)