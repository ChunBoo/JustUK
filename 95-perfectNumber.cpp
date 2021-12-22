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

int main()
{
    int n=27;
    std::cout<<n<<" is a perfect number? "<<isPerfectNumber(n)<<"\n";
    return 0;
}