/**
 * Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

 

Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
 

Constraints:

1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.
*/


class Solution {
public:
    int findTheLongestSubstring(string s) {
        const char vowels[]="aeiou";
        vector<int> idx(1<<5,INT_MAX);
        idx[0]=-1;
        int state=0,ans=0;
        for(int i=0;i<s.length();++i){
            for(int j=0;j<5;++j)
                if(s[i]==vowels[j]) state^=1<<j;
            if(idx[state]==INT_MAX) idx[state]=i;
            ans=max(ans,i-idx[state]);
        }
        return ans;
    }
};