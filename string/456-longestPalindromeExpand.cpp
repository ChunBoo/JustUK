#include<iostream>
#include<string>
#include<vector>

using STR=std::string;
using VEC=std::vector<int>;

VEC expand(const STR& s,int l, int r)
{
    while((l>=0)&&(r<s.size())&&(s[l]==s[r]))
    {
        l-=1;
        r+=1;
    }
    l+=1;
    r-=1;
    return VEC{l,r};   
}

STR longestPalindrome(const STR& s)
{
    int n=s.size();
    int L=0,R=-1;
    for(int i=0;i<n;++i)
    {
        VEC res=expand(s,i,i);
        if((res[1]-res[0])>(R-L))
        {
            L=res[0];
            R=res[1];
        }
        VEC res1=expand(s,i,i+1);
        if((res1[1]-res1[0])>(R-L))
        {
            L=res1[0];
            R=res1[1];
        }
    }
    return s.substr(L,R-L+1);
}
int main()
{
    STR s{"abbccccbbaef"};
    std::cout<<longestPalindrome(s);
}