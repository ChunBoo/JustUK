/**
 * Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.

If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.

Note that the word should be built from left to right with each additional character being added to the end of a previous word. 

Example 1
Input: words = ["w","wo","wor","worl","world"]
Output: "world"
Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input: words = ["a","banana","app","appl","ap","apply","apple"]
Output: "apple"
Explanation: Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".

 * 
*/
class Trie{
    public:
        Trie():root_(new TrieNode()){}
        void insert(const string& word){
            TrieNode* p=root_.get();
            for(const char c:word){
                if(!p->children[c-'a'])
                    p->children[c-'a']=new TrieNode();
                p=p->children[c-'a'];
            }
            p->isWord=true;
        }
        bool hasAllPrefixes(const string& word){
            const TrieNode* p=root_.get();
            for(const char c:word){
                if(!p->children[c-'a']) return false;
                p=p->children[c-'a'];
                if(!p->isWord) return false;
            }
            return true;
        }
    private:
        struct TrieNode{
            TrieNode():isWord{false},children(26,nullptr){}
            ~TrieNode(){
                for(auto node:children)
                    delete node;
            }
            bool isWord;
            vector<TrieNode*> children;

        };
        std::unique_ptr<TrieNode> root_;
};

class Solution {
public:
  string longestWord(vector<string>& words) {
            std::sort(words.begin(),words.end(),[](const string& w1,const string& w2){
          if(w1.length()!=w2.length())
            return w1.length()>w2.length();
          return w1<w2;
      });
      Trie trie;
      for(const string& word:words)
        trie.insert(word);
      for(const string& word:words)
        if(trie.hasAllPrefixes(word)) return word;
    return "";
  }
  string longestWord3(vector<string>& words) {
      std::sort(words.begin(),words.end(),[](const string& w1,const string& w2){
          if(w1.length()!=w2.length())
            return w1.length()>w2.length();
          return w1<w2;
      });

      unordered_set<string> d(words.begin(),words.end());
      for(const string& word:words){
          string prefix;
          bool isValid=true;
          for(int i=0;i<word.length()-1&&isValid;++i)
          {
              prefix+=word[i];
              if(!d.count(prefix)) isValid=false;
          }
          if(isValid) return word;
      }
      return  "";
  }
    string longestWord2(vector<string>& words) {
        string longest;
        unordered_set<string> d(words.begin(),words.end());

        for(const string& word:words){
            if(word.length()<longest.length()||(word.length()==longest.length()
                &&(word>longest)))
                continue;
            string prefix;
            bool isValid=true;
            for(int i=0;i<word.length()-1&&isValid;++i){
                prefix+=word[i];
                if(!d.count(prefix)) isValid=false;
            }
            if(isValid) longest=word;
        }
        return longest;
    }
};