#include<string>
#include<algorithm>
#include<iostream>


bool check( std::string& a, std::string& b)
{
    if(a.size()!=b.size())
        return false;
    std::sort(a.begin(),a.end());
    std::sort(b.begin(),b.end());
    return a==b;
}

int main()
{
    std::string a{"12345"},b{"54332"};
    std::cout<<check(a,b);
    return 0;
}