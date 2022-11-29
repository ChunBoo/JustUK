#include<string>
#include<iostream>
#include<map>

using STR=std::string;
using MAP=std::map<char,int>;
MAP myCounter(const STR& s)
{
    MAP m{};
    for(auto c:s)
    {
        m[c]+=1;
    }
    return m;
}
int longestPalindrome(const STR& s)
{
    if(s.size()==1)
        return 1;
    MAP m=myCounter(s);
    int ans=0,odd=0;
    for(auto &[k,v]:m)
    {
        if((v&1)==0)  //& operator is lower than "==",so need the ()
            ans+=v;
        else
        {
            ans+=(v-1);
            odd=1;
        }
    }
    return ans+odd;
}

int main()
{
    STR s{"abccccdd"};
    std::cout<<longestPalindrome(s);
}