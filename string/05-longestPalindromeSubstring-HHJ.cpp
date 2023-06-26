/**
 * Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
 * 
*/
#include<string>
#include <cmath>
#include<iostream>
using namespace std;

class Solution{
public:
    string longestPalindrome(string s){
        const int len=s.length();
        auto getLen=[&](int l,int r){
            while(l>=0&&r<len&&s[l]==s[r]){
                --l;
                ++r;
            }
            return r-l+1-2;
        };

        int start=0;
        int maxLen=0;
        for(int i=0;i<len;++i){
            int cur=max(getLen(i,i),getLen(i,i+1));
            if(cur>maxLen){
                maxLen=cur;
                start=i-(cur-1)/2;  //Unclear here, for the even case?
            }
        }
        return s.substr(start,maxLen);
    }
};

int main()
{
    string s="abba";
    cout<<Solution().longestPalindrome(s);
}