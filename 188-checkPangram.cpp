//pangram 
#include<set>
#include<iostream>
#include<string>

bool isPangram2(const std::string& words)
{
    std::set<char> s;
    for(auto c:words)
    {
        s.insert(c);
    }
    return s.size()==26;
}

bool isPangram(const std::string& words)
{
    std::set<char> s;
    for(int i=0;i<26;++i)
    {
        char curChar=97+i;
        if(words.find(curChar)==std::string::npos)
            return false;
    }
    return true;
}

int main()
{
    std::string sentences="the quick brown fox jump over the lazy dogs";
    std::cout<<isPangram2(sentences);
    return 0;
}