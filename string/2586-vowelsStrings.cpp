/**
 * You are given a 0-indexed array of string words and two integers left and right.

A string is called a vowel string if it starts with a vowel character and ends with a vowel character where vowel characters are 'a', 'e', 'i', 'o', and 'u'.

Return the number of vowel strings words[i] where i belongs to the inclusive range [left, right].

Example 1:

Input: words = ["are","amy","u"], left = 0, right = 2
Output: 2
Explanation: 
- "are" is a vowel string because it starts with 'a' and ends with 'e'.
- "amy" is not a vowel string because it does not end with a vowel.
- "u" is a vowel string because it starts with 'u' and ends with 'u'.
The number of vowel strings in the mentioned range is 2.
Example 2:

Input: words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4
Output: 3
Explanation: 
- "aeo" is a vowel string because it starts with 'a' and ends with 'o'.
- "mu" is not a vowel string because it does not start with a vowel.
- "ooo" is a vowel string because it starts with 'o' and ends with 'o'.
- "artro" is a vowel string because it starts with 'a' and ends with 'o'.
The number of vowel strings in the mentioned range is 3.
Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 10
words[i] consists of only lowercase English letters.
0 <= left <= right < words.length
Solution:
Iterator overs words, from left to right. Check the first and last element of the string.

Time complexity: O(|right – left + 1|)
Space complexity: O(1)
*/
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        // vector<char> vowels{'a','e','i','o','u'};
        // int ans=0;
        // for(int i=left;i<=right;++i)
        // {
        //     int sz=words[i].size();
        //     if(std::find(vowels.begin(),vowels.end(), words[i][0])!=vowels.end() && 
        //        std::find(vowels.begin(),vowels.end(),words[i][sz-1])!=vowels.end())
        //        ans+=1;
        // }
        // return ans;

        auto isVowel=[](char c){
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };
        return count_if(begin(words)+left, begin(words)+right+1,[&](const string& w){
            return isVowel(w.front())&&isVowel(w.back());
        });
    }
};