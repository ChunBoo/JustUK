//given a list of strings,return the longest common prefix

#include<vector>
#include<string>
#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>
std::string longCommonPrefix(const std::vector<std::string>& words)
{
    if(words.empty())
        return "";

    //find the shortest word
    size_t i=0,k=100;
    for(auto w:words)
    {
        k=std::min(k,w.size());
    }

    while(i<k)
    {
        
        std::set<char> s{};
        for(auto w:words)
        {
            s.insert(w[i]);
        }
        if(s.size()>1)
            break;
        i+=1;
    }
    return words[0].substr(0,i);
}

int main()
{
    std::vector<std::string> words{"won","words","world"};
    std::string res=longCommonPrefix(words);
    std::cout<<res<<'\n';
    return 0;
}