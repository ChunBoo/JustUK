#include<iostream>
#include<string>
#include<vector>
using STR=std::string;
using VEC=std::vector<STR>;

int countPrefix(const VEC& words, const STR& s)
{
    int ans=0;
    for(auto _s:words)
    {
        auto found=s.rfind(_s);
        if(found==0)
        {
            std::cout<<_s<<',';
            ans+=1;
        }
    }
    return ans;
}

int main()
{
    VEC words{"a","b","c","ab","bc","abc"};
    STR s = "abc";
    std::cout<<countPrefix(words,s);
}