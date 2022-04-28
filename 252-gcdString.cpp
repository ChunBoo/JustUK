#include<cmath>
#include<string>
#include<iostream>
#include<numeric>
std::string gcdString(std::string& s,std::string& t)
{
    if(s+t!=t+s)
        return "";
    int k=std::gcd(s.size(),t.size());
    return s.substr(k);
}

int main()
{
    std::string a{"abab"},b{"ababab"};
    std::cout<<gcdString(a,b);
    return 0;
}










