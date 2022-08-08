
#include<string>
#include<iostream>
#include<set>

using STR=std::string;
int firstOccuringChar(const STR& s)
{
    if(s.empty())
        return -1;
    
    std::set<char> seen{};
    for(int i=0;i<s.size();++i)
    {
        char curChar=s[i];
        if(seen.count(curChar)>0)
            return i;
        else
            seen.insert(curChar);
    }
    return -1;
}

int main()
{
    STR s{"abcda"};
    std::cout<<firstOccuringChar(s);
}