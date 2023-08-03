/*
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution1 {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        unordered_map<string,bool> m;
        for(const string& w:words){
            auto it=m.find(w);
            if(it==m.end()){
                bool match=isMatch(w,s);
                ans+=m[w]=match;
            }
            else
                ans+=it->second;
        }
        return ans;
    }

    private:
        bool isMatch(const string& w,const string& S){
            int start=0;
            for (const char c : w) {
              bool found = false;
              for (int i = start; i < int(S.size()); ++i) {
                if (S[i] == c) {
                  start = i + 1;  //Here we should pluse one
                  found = true;
                  break;
                }
              }
              if (!found)
                return false;
            }
            return true;
        }
};

class Solution2 {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(128,vector<int>(0));
        for(int i=0;i<int(s.size());++i)
            pos[s[i]].push_back(i);
        
        int ans=0;
        for(const auto& w:words)
            ans+=isMatch(w,pos);
        return ans;
    }

    private:
        unordered_map<string,bool> m_;
        bool isMatch(const string& w,const vector<vector<int>>& pos){
            if(m_.count(w)) return m_[w];
            int lastIndex=-1;
            for(const char c:w)
            {
                const vector<int> p=pos[c];
                const auto it=std::lower_bound(p.begin(),p.end(),lastIndex+1);
                if(it==p.end()) return m_[w]=false;
                lastIndex=*it;
            }
            return m_[w]=true;
        }
};

int main() {
  string s = "abcde";
  vector<string> words{"a", "bb", "acd", "ace"};
  cout << Solution1().numMatchingSubseq(s, words);
  cout << Solution2().numMatchingSubseq(s, words);
}