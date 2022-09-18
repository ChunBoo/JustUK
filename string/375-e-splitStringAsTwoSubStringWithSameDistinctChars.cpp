#include<string>
#include<iostream>
#include<map>
using STR=std::string;
using MAP=std::map<char,int>;

MAP myCounter(STR s)
{
    MAP ans{};
    for(auto &c:s)
    {
        ans[c]+=1;
    }
    return ans;
}
int split2(STR& s)
{
    if(s.empty())
        return 0;
    MAP c1=myCounter(STR(""));
    MAP c2=myCounter(s);
    int ans=0;
    for(int i=0;i<s.size();++i)
    {
        // STR s1=s.substr(0,i);
        // STR s2=s.substr(i);
        c1[s[i]]+=1;
        c2[s[i]]-=1;
        if(c2[s[i]]==0)
            c2.erase(s[i]);
        if(c1.size()==c2.size())
            ans+=1;

    }
    return ans;
}

int main()
{
    STR s{"aabaa"};
    std::cout<<split2(s);
}