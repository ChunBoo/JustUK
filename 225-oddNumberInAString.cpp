#include<string>
#include<iostream>

std::string largestOddNumber(const std::string& s)
{
    if(s.empty())
        return 0;
    int ans;

    int sz=s.size();
    int lastPos=0;
    for(int i=sz-1;i>=0;--i)
    {
        if((s[i]-'a')&1)
        {
            lastPos=i;
            break;
        }
    }
    return s.substr(0,lastPos);
}

int main()
{
    std::string s{"1234568"};
    std::cout<<largestOddNumber(s);
    return 0;
}