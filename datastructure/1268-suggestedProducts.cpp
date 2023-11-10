/**
 * ou are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.
 

Constraints:

1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 104
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.
*/


struct Trie{
    Trie():nodes(26){}
    ~Trie(){
        for(auto* node:nodes)
            delete node;
    }
    vector<Trie*> nodes;
    vector<const string*> words;

    static void addWord(Trie* root,const string& word){
        for(char c:word){
            if(root->nodes[c-'a']==nullptr) 
                root->nodes[c-'a']=new Trie();
            root=root->nodes[c-'a'];
            if(root->words.size()<3)
                root->words.push_back(&word);
        }
    }
    static vector<vector<string>> getWords(Trie* root,const string& prefix){
        vector<vector<string>> ans(prefix.size());
        for(int i=0;i<prefix.size();++i){
            char c=prefix[i];
            root=root->nodes[c-'a'];
            if(!root) break;
            for(auto* word:root->words)
                ans[i].push_back(*word);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(begin(products),end(products));
        Trie root;
        for(const auto& product:products)
            Trie::addWord(&root,product);
        return Trie::getWords(&root,searchWord);
    }
};