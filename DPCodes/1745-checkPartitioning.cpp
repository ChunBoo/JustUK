/**
 * Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​

A string is said to be palindrome if it the same string when reversed.

 

Example 1:

Input: s = "abcbdd"
Output: true
Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
Example 2:

Input: s = "bcbddxy"
Output: false
Explanation: s cannot be split into 3 palindromes.
 

Constraints:

3 <= s.length <= 2000
s​​​​​​ consists only of lowercase English letters.
*/


class Solution {
public:
    bool checkPartitioning(string s) {
        const int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,1));

        for(int l=2;l<=n;++l)
        {
            for(int i=0,j=i+l-1;j<n;++i,++j)
                dp[i][j]=s[i]==s[j]&&(dp[i+1][j-1]);
        }

        for(int i=1;i<n;++i)
        {
            for(int j=i;j<n-1;++j)
            {
                if(dp[0][i-1]&&dp[i][j]&&dp[j+1][n-1])
                    return true;
            }
        }
        return false;
    }
};