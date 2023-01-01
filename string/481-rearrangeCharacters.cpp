#include<iostream>
#include<string>
#include<unordered_map>

using MAP=std::unordered_map<char,int>;
using STR=std::string;

MAP _counter(const STR& s)
{
    MAP ans{};
    for(auto &c:s)
    {
        ans[c]+=1;
    }
    return ans;
}

int rearrangeChars(const STR& s,const STR& target)
{
    MAP S{_counter(s)};
    int ans=0;
    while(true)
    {
        for(auto &c:target)
        {
            if(S[c]>0)
                S[c]-=1;
            else    
                return ans;
        }
        ans+=1;
    }
    return ans;
}
int rearrangeCharacters(const STR& s,const STR& target)
{
    MAP S{_counter(s)},T{_counter(target)};
    int ans=INT_MAX;
    for(auto &c:target)
    {
        ans=std::min(ans,S[c]/T[c]);
    }
    return  ans==INT_MAX?0:ans;
}

int main()
{
    STR s = "ilovecodingonleetcode",target = "codef";
    std::cout<<rearrangeChars(s,target)<<'\n';
    std::cout<<rearrangeCharacters(s,target);
}