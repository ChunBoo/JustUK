#include<iostream>
#include<string>

int findCharFromString(const std::string& s,char c)
{
    if(s.empty())
        return -1;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==c)
            return i;
    }
    return -1;
}

int main()
{
    std::string s{"abcd"};
    std::cout<<findCharFromString(s,'t');
    return 0;
}