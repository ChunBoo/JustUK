/**
 * @file 1-2864-maximumOddBinaryNumber.cpp
 * 
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-13
 * 
 * @copyright Copyright (c) 2024
 * You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.

Note that the resulting string can have leading zeros.

 

Example 1:

Input: s = "010"
Output: "001"
Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".
Example 2:

Input: s = "0101"
Output: "1001"
Explanation: One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100". So the answer is "1001".
 

Constraints:

1 <= s.length <= 100
s consists only of '0' and '1'.
s contains at least one '1'.
 */



// class Solution {
// public:
//     string maximumOddBinaryNumber(string s) {
//         const int n=s.size();
//         string ans(n,'0');
//         int oneCnt=0;
//         for(int i=0;i<n;++i){
//             if(s[i]=='1')
//                 oneCnt+=1;
//         }
//         // if(oneCnt==1)
//             ans[n-1]='1';
        
//             for(int k=0;k<oneCnt-1;++k){
//                 ans[k]='1';
//             }
//         return ans;
//     }   
// };

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0, n = s.size();
        for (auto &c : s){
            if (c=='1') cnt ++;
        }
        string ans = "";
        while (cnt >1){
            ans.push_back('1');
            cnt--; n--;
        }
        
        while (n>1){
            ans.push_back('0');
            n--;
        }
        ans.push_back('1');
        return ans;
    }
};
