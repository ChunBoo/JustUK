#include<string>
#include<iostream>
#include<cmath>
int getCountOfPanlindrome(const std::string& str,int k)
{
    int sz=str.size();
    if(k%2==1)
    {
        return sz*std::pow(sz,k/2);
    }
    else
        return std::pow(sz,k/2);
}


int main()
{
    std::string str="abc";
    // std::cout<<std::pow(2,4);
    int res=getCountOfPanlindrome(str,4);
    std::cout<<res<<'\n';
    return 0;
}