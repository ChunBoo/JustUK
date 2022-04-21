#include<string>
#include<iostream>


char checkDifference(const std::string& s,const std::string& t)
{
    std::string tmp=s+t;
    char ans=0;
    for(auto c:tmp)
    {
        ans^=c;
    }
    return ans;
}

int main()
{
    std::string s{"abc"},t{"abcc"};
    std::cout<<checkDifference(s,t);
    return 0;
}