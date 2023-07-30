/**
 * Given a string licensePlate and an array of strings words, find the shortest completing word in words.

A completing word is a word that contains all the letters in licensePlate. Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. If a letter appears more than once in licensePlate, then it must appear in the word the same number of times or more.

For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice. Possible completing words are "abccdef", "caaacab", and "cbca".

Return the shortest completing word in words. It is guaranteed an answer exists. If there are multiple shortest completing words, return the first one that occurs in words.

 

Example 1:

Input: licensePlate = "1s3 PSt", words = ["step","steps","stripe","stepple"]
Output: "steps"
Explanation: licensePlate contains letters 's', 'p', 's' (ignoring case), and 't'.
"step" contains 't' and 'p', but only contains 1 's'.
"steps" contains 't', 'p', and both 's' characters.
"stripe" is missing an 's'.
"stepple" is missing an 's'.
Since "steps" is the only word containing all the letters, that is the answer.
*/
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> l(26,0);
        for(const char ch:licensePlate)
            if(isalpha(ch)) ++l[tolower(ch)-'a'];
        
        string ans;
        int minl=INT_MAX;
        for(const string& w:words){
            if(w.length()>=minl) continue;
            if(!match(l,w)) continue;
            minl=w.length();
            ans=w;
        }
        return ans;
    }
private:
    bool match(const vector<int>& l,const string& w)
    {
        vector<int> c(26,0);
        for(const char ch:w)
            ++c[tolower(ch)-'a'];
        for(int i=0;i<26;++i)
            if(c[i]<l[i]) return false;
        return true;
    }
};