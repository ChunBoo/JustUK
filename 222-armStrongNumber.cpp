#include<string>
#include<iostream>
#include<cmath>
int numberOfDigits(int n)
{
    return std::log10(n)+1;  // this is the most effective method
    if(n==0)
        return 1;
    int ans=0;
    while(n)
    {
        ++ans;
        n/=10;
    }
    return ans;
}

bool isArmStrong(int v)
{
    int digits=numberOfDigits(v);
    int ans=0;
    int temp=v;
    while(v)
    {
        ans+=std::pow((v%10),digits);
        v/=10;
    }
    return ans==temp;
}

int main()
{
    int val=1234;
    // std::cout<<numberOfDigits(val);
    std::cout<<isArmStrong(153);
    return 0;
}