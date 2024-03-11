/**
 * @brief You are given a string title consisting of one or more words separated by a single space, where each word consists of English letters. Capitalize the string by changing the capitalization of each word such that:

If the length of the word is 1 or 2 letters, change all letters to lowercase.
Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
Return the capitalized title.

 

Example 1:

Input: title = "capiTalIze tHe titLe"
Output: "Capitalize The Title"
Explanation:
Since all the words have a length of at least 3, the first letter of each word is uppercase, and the remaining letters are lowercase.
Example 2:

Input: title = "First leTTeR of EACH Word"
Output: "First Letter of Each Word"
Explanation:
The word "of" has length 2, so it is all lowercase.
The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.
Example 3:

Input: title = "i lOve leetcode"
Output: "i Love Leetcode"
Explanation:
The word "i" has length 1, so it is lowercase.
The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.
 

Constraints:

1 <= title.length <= 100
title consists of words separated by a single space without any leading or trailing spaces.
Each word consists of uppercase and lowercase English letters and is non-empty.
 * 
 */

// class Solution {
// public:
//     string capitalizeTitle(string title) {
//         const int n=title.length();
//         vector<string> words;
//         std::istringstream iss(title);
//         string word;
//          while (iss >> word) {
//         words.push_back(word);
//         }
//         string ans;
//         for(int i=0;i<words.size();++i)
//         {
//            string s=words[i];
//            int len=s.size();
//            if(len<3)
//            {
//             for(int i=0;i<len;++i)
//             {
//                 if(s[i]>='A'&&s[i]<='Z')
//                     s[i]=(s[i]-'A'+'a');
//             }
//            }
//            else
//            {
//                 for(int i=0;i<len;++i)
//                 {
//                     if(i==0)
//                     {
//                     if(s[i]>='a'&&s[i]<='z')
//                         s[i]=(s[i]-'a'+'A');
//                     }
//                     else
//                     {
//                         if(s[i]>='A'&&s[i]<='Z')
//                         s[i]=(s[i]-'A'+'a');
//                     }
//                 }
//             }
//             if(i==0)
//                ans+=s;
//             else
//             ans+=(" "+s);
//         }
//         return ans;
//     }
// };

// class Solution{
//     public:
//         string capitalizeTitle(string title){
//             istringstream iss(title);
//             string ans,word;
//             while(iss>>word){
//                 if(!ans.empty())
//                     ans+= ' ';
//                 if(word.size()>2){
//                     ans+=toupper(word[0]);
//                     word=word.substr(1);
//                 }
//                 for(char c:word)
//                     ans+=tolower(c);
//             }
//             return ans;
//         }
// };

class Solution{
    public:
        string capitalizeTitle(string title){
            const int n=title.size();
            int l=0,r=0;
            while(r<n){
                while(r<n&&title[r]!=' '){
                    ++r;
                }
                if(r-l>2)
                    title[l++]=toupper(title[l]);
                while(l<r)
                    title[l++]=tolower(title[l]);
                l=++r;
            }
            return title;
        }
};