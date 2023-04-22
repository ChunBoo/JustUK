/*
You are given a binary string s consisting only of zeroes and ones.

A substring of s is considered balanced if all zeroes are before ones and the number of zeroes is equal to the number of ones inside the substring. Notice that the empty substring is considered a balanced substring.

Return the length of the longest balanced substring of s.

A substring is a contiguous sequence of characters within a string.
Example 1:
Input: s = "01000111"
Output: 6
Explanation: The longest balanced substring is "000111", which has length 6.
*/
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int zeros=s[0]=='0',ones=s[0]=='1';
        int n=s.size();
        int ans=0;
        char prev='a';
        for(int i=0;i<n;++i)
        {
            if(s[i]=='1')
            {
                ones+=1;
                if(zeros>=ones)
                    ans=max(ans,ones*2);
            }
            else
            {
                ones=0;
                if(s[i]==prev)
                    zeros+=1;
                else
                    zeros=1;
            }
            prev=s[i];
        }
        return ans;
    }
};