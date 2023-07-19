#include<memory>
#include<vector>
#include<string>
#include<iostream>
using namespace std;


class Trie{
    public:
        Trie():m_root(new TrieNode()){
            cout<<"create smart pointer.\n";
        };
        //insert
        void insert(const string& word){
            TrieNode* p=m_root.get();
            for(const char c:word)
            {
                if(!p->children[c-'a'])
                    p->children[c-'a']=new TrieNode();
                p=p->children[c-'a'];
            }
            p->isWord=true;
        }

        bool search(const string& word) const {
            const TrieNode* p=find(word);
            return p&&p->isWord;
        }
        
        bool startWith(const string& prefix) const{
            return find(prefix) !=nullptr;
        }

    private:
        struct  TrieNode{
            TrieNode():isWord(false),children(26,nullptr){
                cout<<"Ctor trieNode.\n";
            }
            ~TrieNode(){
                cout<<"dtor of TrieNode.\n";
                for(TrieNode* child:children)
                    if(child)
                        delete child;
            }
            bool isWord;
            vector<TrieNode*>  children;
        };  
        const TrieNode* find(const string& prefix) const{
            const TrieNode* p=m_root.get();
            for(const char c:prefix)
            {
                p=p->children[c-'a'];
                if(!p)
                    break;
            }
            return p;
        }
        std::unique_ptr<TrieNode> m_root;
};


int main()
{
    vector<string> slist{"at","apt","pat"};
    Trie trie=Trie();
    for(auto &s:slist){
        trie.insert(s);
    }
    cout<<trie.search("at")<<'\n';
    cout<<trie.search("ta")<<'\n';
}