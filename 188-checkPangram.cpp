//pangram sentence means the sentence contains all of the 26-chars-little case
#include<set>
#include<iostream>
#include<string>

bool isPangram2(const std::string& words)
{
    for(int i=0;i<26;++i)
    {
        if(words.find(i+97)==std::string::npos)
            return false;
    }
    return true;
}


bool isPangram(const std::string& words) //used std::set
{

    std::set<char> s{};
    for(auto c:words)
    {
        s.insert(c);
    }
    return s.size()==27;
}


int main()
{
    std::string sentences="the quick brown fox jump over the lazy dogs";
    std::cout<<isPangram(sentences);
    return 0;
}