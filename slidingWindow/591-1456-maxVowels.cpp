/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
*/

class Solution {
public:
    int maxVowels(string s, int k) {
        string vowels{'a','e','i','o','u'};
        int ans=0,win=0;
        for(int i=0;i<k;++i)
        {
            if(vowels.find(s[i])!=std::string::npos)
                win+=1;
        }
        ans=win;
        for(int i=k;i<s.size();++i)
        {
            if(vowels.find(s[i])!=std::string::npos)
                win+=1;
            if(vowels.find(s[i-k])!=std::string::npos)
                win-=1;
            ans=max(ans,win);
        }
        return ans;
    }
};