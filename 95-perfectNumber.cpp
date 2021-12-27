// 1+2+4+7+14=28,is a perfect number
#include<iostream>

bool isPerfectNumber(int n)
{
    int sum=0;
    int i=1;
    while(i*2<=n)  // i*i<=n 
    {
        if(n%i==0)
        {
            sum+=i;
            // if(i*i!=n)
                // sum+=n/i;
        }
        ++i;
    }
    return sum==n;
}

bool isPerfectNumberWithPowerOf2(int n)
{
    int sum=0;
    int i=1;
    while(i*i<=n)
    {
        if(n%i==0)
        {
            sum+=i;
            if(i*i!=n)
                sum+=n/i;
        }
        ++i;
    }
    return sum-n==n;
}

int main()
{
    int n=28;
    std::cout<<n<<" is a perfect number? "<<isPerfectNumberWithPowerOf2(n)<<"\n";
    return 0;
}