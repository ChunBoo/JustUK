#include<string>
#include<vector>
#include<iostream>

class Trie
{
    private:
        std::vector<Trie*> m_data;
        bool m_leaf{false};
    public:
        void insert(const std::string&);
        bool search(const std::string&);
};

void Trie::insert(const std::string& s)
{
    if(s.empty())
        return ;
    for(auto i:s)
    {
        
    }
}