/***
 * Given a string s consisting of lowercase English letters. Perform the following operation:

Select any non-empty 
substring
 then replace every letter of the substring with the preceding letter of the English alphabet. For example, 'b' is converted to 'a', and 'a' is converted to 'z'.
Return the 
lexicographically smallest
 string after performing the operation.

 

Example 1:

Input: s = "cbabc"

Output: "baabc"

Explanation:

Perform the operation on the substring starting at index 0, and ending at index 1 inclusive.

Example 2:

Input: s = "aa"

Output: "az"

Explanation:

Perform the operation on the last letter.

Example 3:

Input: s = "acbbc"

Output: "abaab"

Explanation:

Perform the operation on the substring starting at index 1, and ending at index 4 inclusive.

Example 4:

Input: s = "leetcode"

Output: "kddsbncd"

Explanation:

Perform the operation on the entire string.

 

Constraints:

1 <= s.length <= 3 * 105
s consists of lowercase English letters
 */



class Solution {
public:
    string smallestString(string s) {
        const char target='a';
        auto it=find_if(begin(s),end(s),[target](char c){
            return c!=target;
        });

        int indexOfFirstNonA=distance(begin(s),it);
        if(indexOfFirstNonA==s.length()){
            return s.substr(0,s.size()-1)+'z';
        }
        size_t indexOfFirstA_AfterFirstNonA=s.find('a',indexOfFirstNonA);
        if(indexOfFirstA_AfterFirstNonA==string::npos){
            indexOfFirstA_AfterFirstNonA=s.size();
        }

        string ans;
        for(int i=0;i<s.size();i++){
            if(indexOfFirstNonA<=i&&i<indexOfFirstA_AfterFirstNonA){
                ans.push_back(static_cast<char>(s[i]-1));
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};