#include<memory>
#include<vector>
#include<string>
using namespace std;


class Trie{
    public:
        Trie():m_root(new TrieNode()){};
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
            TrieNode():isWord(false),children(26,nullptr){}
            ~TrieNode(){
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