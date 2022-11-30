#include<string>
#include<iostream>

using STR=std::string;



bool isPalindrome(const STR& s)
{
    int l=0,r=s.size()-1;
    while(l<r)
    {
        if(s[l]!=s[r])
            return false;
        l+=1;
        r-=1;
    }
    return true;
}

STR longestPalindrome(const STR& s)
{
    if(s.empty() ||s.size()==1)
        return s;
    int n=s.size();
    int l=-1,r=-1;
    for(int i=0;i<n;++i)
    {
        for(int j=n-1;j>-1;--j)   //revert sequence is important here ,which can optimize the time complexity
        {
            STR tString=s.substr(i,j-i+1);
            if(isPalindrome(tString))
            {
                if((j-i)>(r-l))
                {
                    l=i;
                    r=j;
                }
                break;
            }
        }
    }
    return s.substr(l,r-l+1);
}

int main()
{
    STR s{"abbccccdbbaef"};
    std::cout<<longestPalindrome(s);
}