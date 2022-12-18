#include<string>
#include<vector>
#include<iostream>
#include<set>
using STR=std::string;
using VEC=std::vector<STR>;
using SET=std::set<STR>;
bool dfs(int i,const STR& s,const VEC& words)
{
    int sz=s.size();
    if(i==sz)
        return true;
    SET st(words.begin(),words.end());
    for(int x=i+1;x<=sz;++x)
    {
        STR tmp=s.substr(i,x-i);
        auto search=st.find(tmp);
        if((search!=st.end())&& dfs(x,s,words))
            return true;
    }
    return false;    
}
bool canWordBreak(const STR& s, const VEC& words)
{
    return dfs(0,s,words);
}

int main()
{
    STR s = "applepenapple";
    VEC w{"apple","pen1"};
    std::cout<<canWordBreak(s,w);
}