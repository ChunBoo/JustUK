/***
 * We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

 

Example 1:

Input: word = "USA"
Output: true
Example 2:

Input: word = "FlaG"
Output: false
 

Constraints:

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.
 */

class Solution {
public:
    bool detectCapitalUse(string word) {
        const int n=word.size();
        // bool isFirstCapital=word[0]>='A'&&word[0]<='Z';
        // bool isPrevCharCapital =isFirstCapital;
        // for(int i=1;i<n;i++){
        //     char curChar=word[i];
        //     bool isCurrCharCaptial=curChar>='A'&&curChar<='Z';
        //     if(isFirstCapital){
        //         if(isPrevCharCapital!=isCurrCharCaptial&&i>1){
        //             return false;
        //         }
        //     }
        //     else{
        //         if(curChar>='A'&&curChar<='Z'){
        //             return false;
        //         }
        //     }
        //     isPrevCharCapital=isCurrCharCaptial;
        // }
        // return true;

        if(n>=2&&islower(word[0])&&isupper(word[1])){
            return false;
        }

        for(int i=2;i<n;i++){
            if(islower(word[i])^islower(word[1]))
                return false;
        }
        return true;
        
    }
};