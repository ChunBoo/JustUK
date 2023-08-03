/**
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 * 
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1=s1.size();
        int l2=s2.size();
        vector<int> c1(26);
        vector<int> c2(26);
        for(const char c:s1)
            ++c1[c-'a'];
        for(int i=0;i<l2;++i){
            if(i>=l1){
                --c2[s2[i-l1]-'a'];
            }
            ++c2[s2[i]-'a'];
            if(c1==c2) return true;
        }
        return false;
    }
};