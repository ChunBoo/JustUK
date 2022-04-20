//given a list of strings,and broken chars,return the total count of maximum chars

#include<set>
#include<vector>
#include<string>
#include<iostream>


int maxCountOfWords( std::string& strs,const std::string& brokens)
{
    if(strs.empty())
        return 0;
    std::vector<std::string> tmp{};
    std::set<char> b{};
    for(auto c:brokens)
        b.insert(c);
    size_t pos=strs.find(" ");
    // size_t pre=0;
    int ans=0;
    while(pos!=std::string::npos)
    {
        tmp.push_back(strs.substr(0,pos));
        strs=strs.substr(pos+1);
        pos=strs.find(" ");
    }
    for(auto s:tmp)
    {
        std::cout<<s<<'\n';
        bool isNotIn=true;
        for(auto c:s)
        {
            if(b.find(c)!=b.end())
            {
                isNotIn=false;
                break;
            }
        }
        if(isNotIn)
            ans+=s.size();
    }
    return ans;
}

int main()
{
    std::string s{"Tom likes playing "};
    std::string broken{"ok"};
    std::cout<<maxCountOfWords(s,broken);
    return 0;
}