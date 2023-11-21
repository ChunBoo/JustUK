/**
 * Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]
Explanation 
WordDictionary wordDictionary = new WordDictionary(); 
wordDictionary.addWord("bad"); 
wordDictionary.addWord("dad"); 
wordDictionary.addWord("mad"); 
wordDictionary.search("pad"); // return False 
wordDictionary.search("bad"); // return True 
wordDictionary.search(".ad"); // return True 
wordDictionary.search("b.."); // return True
Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search.
Solution: Hashtables
The first hashtable stores all the words, if there is no dot in the search pattern. Do a full match.

There are also per length hashtable to store words of length k. And do a brute force match.

Time complexity: Init: O(n*l)
search: best: O(l) worst: O(n*l)
*/

class WordDictionary {
public:
    WordDictionary() {

    }
    
    void addWord(string word) {
        words.insert(word);
        ws[word.size()].insert(word);
    }
    
    bool search(string word) {
        if(word.find(".")==std::string::npos)
            return words.count(word);
        for(const string& w:ws[word.size()])
        if(match(word,w))
            return true;
        return false;
    }
    bool match(const string& word,const string& w)
    {
        for(int i=0;i<word.size();++i)
        {
            if(word[i]=='.') continue;
            if(word[i]!=w[i]) return false;
        }
        return true;
    }
private:
    unordered_set<string> words;
    unordered_map<int,unordered_set<string>> ws;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */