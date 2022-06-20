#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<iterator>
using DT=std::vector<std::string>;

std::string constructWord(const DT& rules)
{
    std::set<char> s{};
    std::map<char,char> m{};
    std::string ans{};
    char cur{};

    for(auto &r:rules)
    {
        int n{};
        n=r.find('>');
        s.insert(r[n-1]);  //start
        s.insert(r[n+1]);  //end
    }

    for(auto&r:rules)
    {
        int n{};
        n=r.find('>');
        s.erase(r[n+1]);
        m[r[n-1]]=r[n+1];
    }

    std::set<char>::iterator iter=s.begin();
    ans+=*iter;
    char tmp=*iter;
    auto pos=m.find(tmp);
    while(pos!=m.end())
    {
        tmp=m[pos->first];
        ans+=tmp;
        pos=m.find(tmp);
    }
    
    return ans;
}

int main()
{
    DT rules{"E>R","R>I","I>C"}; //rules=["E>R","R>I","I>C"]
    std::cout<<constructWord(rules);
    return 0;
}