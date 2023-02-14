
#include<iostream>
#include<cmath>
using std::cout;


int concatenateBin(int n)
{
    int ans=0;
    int b=0;
    int MOD=std::pow(10,9)+7;
    for(int i=1;i<n+1;++i)
    {
        if((i&(i-1))==0)
            b+=1;
        ans<<=b;
        ans+=i;
        ans%=MOD;
    }
    return ans;
}

int main()
{
    cout<<concatenateBin(3);
}