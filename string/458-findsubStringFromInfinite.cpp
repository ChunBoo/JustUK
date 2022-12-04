#include<iostream>
#include<string>

using STR=std::string;

STR findSubString(const STR& s,int i,int j)
{
    STR ans{};
    for(int idx=i;idx<j;++idx)
    {
        ans+=s[idx%s.size()];
    }
    return ans;
}
STR findSubString2(const STR& s,int i,int j)
{
    int n=s.size();
    
}

int main()
{
    STR s{"hi"};//{"tiger"};
    int i=2,j=6;
    std::cout<<findSubString(s,i,j);
}