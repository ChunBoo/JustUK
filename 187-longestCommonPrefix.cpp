//given a list of strings,return the longest common prefix
//used a set to save current subchar of each words
#include<vector>
#include<string>
#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>
//#include <bits/stdc++.h>  //for INT_MAX
std::string longCommonPrefix(const std::vector<std::string>& words)
{
    if(words.empty())
        return "";
    //findout the shortest word
    size_t k=INT_MAX;
    for(auto w:words)
        k=std::min(k,w.size());

    int i=0;
    while(i<k)
    {
        std::set<char> s{};
        for(auto w:words)
        {
            s.insert(w[i]);
        }
        if(s.size()>1)
            break;
        ++i;
    }
    return words[0].substr(0,i);
}

int main()
{
    int k=INT_MAX;
    std::cout<<k<<'\n';
    std::vector<std::string> words{"wor","words","world"};
    std::string res=longCommonPrefix(words);
    std::cout<<res<<'\n';
    return 0;
}