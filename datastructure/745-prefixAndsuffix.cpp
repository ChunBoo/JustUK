/**
 * Design a special dictionary that searches the words in it by a prefix and a suffix.

Implement the WordFilter class:

WordFilter(string[] words) Initializes the object with the words in the dictionary.
f(string pref, string suff) Returns the index of the word in the dictionary, which has the prefix pref and the suffix suff. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.
 

Example 1:

Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]
Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = "e".
 

Constraints:

1 <= words.length <= 104
1 <= words[i].length <= 7
1 <= pref.length, suff.length <= 7
words[i], pref and suff consist of lowercase English letters only.
At most 104 calls will be made to the function f.

 * 
 * 
*/

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        int index=0;
        for(const string& word:words){
            int n=word.length();
            vector<string> prefixes(n+1,"");
            vector<string> suffixes(n+1,"");
            for(int i=0;i<n;++i){
                prefixes[i+1]=prefixes[i]+word[i];
                suffixes[i+1]=word[n-i-1]+suffixes[i];
            }
            for(const string& prefix:prefixes)
                for(const string& suffix:suffixes)
                    filters_[prefix+"_"+suffix]=index;
            ++index;
        }
    }
    
    int f(string pref, string suff) {
        const string key=pref+"_"+suff;
        auto it=filters_.find(key);
        if(it!=filters_.end()) return it->second   ;
        return -1;
    }
    private:
        unordered_map<string,int> filters_;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */