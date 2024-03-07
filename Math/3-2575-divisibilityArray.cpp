/**
 * @file 3-2575-divisibilityArray.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024
 * 
 * You are given a 0-indexed string word of length n consisting of digits, and a positive integer m.

The divisibility array div of word is an integer array of length n such that:

div[i] = 1 if the numeric value of word[0,...,i] is divisible by m, or
div[i] = 0 otherwise.
Return the divisibility array of word.

 

Example 1:

Input: word = "998244353", m = 3
Output: [1,1,0,0,0,1,1,0,0]
Explanation: There are only 4 prefixes that are divisible by 3: "9", "99", "998244", and "9982443".
Example 2:

Input: word = "1010", m = 10
Output: [0,1,0,1]
Explanation: There are only 2 prefixes that are divisible by 10: "10", and "1010".
 

Constraints:

1 <= n <= 105
word.length == n
word consists of digits from 0 to 9
1 <= m <= 109
 * 
 * 
 * 
 * 当m很大时，表示取余结果的cur也要开的比较大，因为cur本身的取值范围是[0, m - 1]，如果还是用int，会溢出。
(a * 10 + b) % m == (a % m * 10 + b) % m 所以我们每次只需要保存当前数取余后的值，参与下一次运算即可。
如果不这样做，当word很大时，a变得很大，大到没有任何类型的数可以装下它。比如最后一个测试用例。
 */


class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        //  n=ax10+b-->  (ax10+b) mod m =(a mod m x10 + b) mod m
        vector<int> ans;
        long long cur=0;
        for(char& c:word){
            cur=(cur*10+(c-'0'))%m;
            ans.push_back(cur==0?1:0);
        }
        return ans;
    }
};