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
#include<iostream>
#include<cmath>
#include<string>

using namespace std;
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans=0;
        int ones=s[0]=='0',zeros=s[0]=='1';
        int n=s.size(),prev=s[0];
        for(int i=1;i<n;++i)
        {
            if(s[i]=='1')
            {
                // zeros=0;
                ones+=1;
                if(zeros>=ones)
                    ans=max(ans,ones*2);
            }
            else  //s[i]=='0'
            {
                ones=0;
                if(s[i]==prev)
                {
                    zeros+=1;
                }
                else
                    zeros=1;
            }
            prev=s[i];
        }
        return ans;
    }
};

int main()
{
    string s{"01000111001"};
    cout<<Solution().findTheLongestBalancedSubstring(s);
}