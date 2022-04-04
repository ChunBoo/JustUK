//armstrong number is 153=1^3+5^3+3^3
#include<string>
#include<iostream>
#include<cmath>   //for std::log10

int numberOfDigitsWithLogs(int v)
{
    return std::log10(v)+1;   //method: 10^2=100,log10(100)=2
}

int numberOfDigits(int n)
{
    int ans=0;
    while(n)
    {
        ans+=1;
        n/=10;
    }
    return ans;
}

bool isArmStrong(int v)
{
    int digits=numberOfDigitsWithLogs(v);
    // int ans=0;
    for(int i=1;i<1000;++i)
    {   
        int ans=0;
        int val=i,v=i;
        while(v)
        {
            ans+=std::pow(v%10,digits);
            v/=10;
        }
        if(ans==val)
            std::cout<<i<<',';
    }
}

int main()
{
    int val=1234;
    std::cout<<numberOfDigitsWithLogs(val)<<'\n';
    std::cout<<isArmStrong(153);
    return 0;
}