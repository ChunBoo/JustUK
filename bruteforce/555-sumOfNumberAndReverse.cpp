#include<iostream>
#include<string>

using std::cout;
using STR=std::string;

int reverse(int n)
{
    int ans{};
    while(n)
    {
        int tmp=n%10;
        ans=ans*10+tmp;
        n/=10;
    }
    return ans;
}

bool sumOfNumberAndReverse(int n)
{
    bool ans{};
    for(int i=n/2;i<=n;++i)
    {
        if((i+reverse(i))==n)
            return true;
    }
    return false;
}

int main()
{
    cout<<sumOfNumberAndReverse(443);
}