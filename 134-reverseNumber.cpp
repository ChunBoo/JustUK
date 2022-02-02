//given a number which 32-bits,just reverse it's value

#include<iostream>

int reverseValue(int n)
{
    int ans=0;
    int p=31;
    while(n>0)
    {
        ans|=((n&1)<<p);
        p-=1;
        n>>=1;
    }
    return ans;
}

int main()
{
    int value=1;
    int res=reverseValue(value);
    std::cout<<"reversed result is: "<<res<<'\n';

    return 0;
}