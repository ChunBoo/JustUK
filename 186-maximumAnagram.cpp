#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>
int maximumAnagram(std::vector<std::string>& words)
{
    if(words.empty())
        return 0;

    std::map<std::string,int> nb;

    for(auto w:words)
    {
        std::sort(w.begin(),w.end());
        nb[w]+=1;
    }

    int ans=0;
    for(auto w:nb)
    {
        ans=std::max(ans,w.second);
    }
    return ans;
}
int main()
{
    std::vector<std::string> words{"abc","acbd","bca","ac","bc"};
    std::cout<<maximumAnagram(words)<<'\n';
    return 0;
}