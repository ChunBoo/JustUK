#include<iostream>
#include<string>

using STR=std::string;

bool isPrefix(const STR& p,const STR& s)
{
    if(p.size()>s.size())
        return false;
    
    int i=0;
    while(i<p.size())
    {
        if(p[i]!=s[i])
            return false;
        i+=1;
    }
    return true;
}


bool isSuffix(const STR& p, const STR& s)
{
    if(p.size()>s.size())
        return false;
    
    int i=p.size()-1,j=s.size()-1;
    while(i>=0)
    {
        if(p[i]!=s[j])
            return false;
        i-=1;
        j-=1;
    }
    return true;
}

int main()
{
    STR p{"abcd"},s{"abcdefgabcd"};
    std::cout<<isPrefix(p,s);
    std::cout<<isSuffix(p,s);
    return 0;
}