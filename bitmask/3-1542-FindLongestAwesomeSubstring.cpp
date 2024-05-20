/***
 * You are given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps in order to make it a palindrome.

Return the length of the maximum length awesome substring of s.

 

Example 1:

Input: s = "3242415"
Output: 5
Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.
Example 2:

Input: s = "12345678"
Output: 1
Example 3:

Input: s = "213123"
Output: 6
Explanation: "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.
 

Constraints:

1 <= s.length <= 105
s consists only of digits.
*/

class Solution {
public:
    int longestAwesome(string s) {
        const int kInf=1e9;
        int n=s.size();
        vector<int> idx(1024,kInf);

        int ans=0;
        idx[0]=-1;
        int mask=0;//0:even, 1:odd
        for(int i=0;i<n;i++){
            mask^=(1<<(s[i]-'0'));
            ans=max(ans,i-idx[mask]);
            for(int j=0;j<10;j++){
                ans=max(ans, i-idx[mask^(1<<j)]);
            }
            idx[mask]=min(idx[mask],i);
        }
        return ans;
    }
};