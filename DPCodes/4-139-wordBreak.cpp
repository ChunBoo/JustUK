
/**
 * @brief Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
 * 
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        words_=set<string>{wordDict.begin(),wordDict.end()};
        // for(const string& w:wordDict)
        //     cached_.emplace(w,true);
        return dp(s);
    }
private:
    set<string> words_;
    map<string,bool> cached_;
    bool dp(const string& s){
        if(cached_.count(s))
            return cached_[s];
        if(words_.count(s))
            return cached_[s]=true;
        //int minLen=min(20,int(s.size()));
        for(int i=1;i<s.length();++i)
        {
            string preStr=s.substr(0,i);
            string postStr=s.substr(i);
            if(words_.count(preStr) && dp(postStr))
            {
                cached_[s]=true;
                return true;
            }
        }
        return cached_[s]=false;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      // Mark evert word as breakable.
      for (const string& word : wordDict)
        mem_.emplace(word, true);
 
      // Query the answer of the original string.
      return wordBreak(s);
    }
    
    bool wordBreak(const string& s) {
      // In memory, directly return.
      if (mem_.count(s)) return mem_[s];
 
      // Try every break point.
      for (int j = 1; j < s.length(); j++) {         
          auto it = mem_.find(s.substr(j));
          // Find the solution for s.
          if (it != mem_.end() && it->second && wordBreak(s.substr(0, j)))
            return mem_[s] = true;
      }
      
      // No solution for s, memorize and return.
      return mem_[s] = false;
    }
private:
    unordered_map<string, bool> mem_;
};