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
    int k=j-i;
    // STR p(k+1,s.c_str());
    STR p{};
    for(int c=0;c<k+1;++c)
        p+=s;
    return p.substr(i,k);
}

int main()
{
    STR s{"tiger"};//s{"hi"};//{"tiger"};
    int i=6,j=8;
    std::cout<<findSubString2(s,i,j);
}