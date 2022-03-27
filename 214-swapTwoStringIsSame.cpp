#include<string>
#include<iostream>

bool isSameAfterSwapping(const std::string& s, const std::string& t)
{
    int x=0;
    for(auto i:s)
        x^=i-'a';

    for(auto i:t)
        x^=i-'a';

    return x==0;
}

int main()
{
    std::string s="ab",t="ba";
    std::cout<<isSameAfterSwapping(s,t);
    return 0;
}