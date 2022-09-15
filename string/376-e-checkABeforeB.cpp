#include<string>
#include<iostream>

using STR=std::string;

bool checkAllAbeforeB(STR s)
{
    return s.find("ba")==std::string::npos;
}

int main()
{
    STR s{"abb"};
    std::cout<<checkAllAbeforeB(s);
}
