// check a number is power of two?
#include<iostream>
// #include<>

bool isPowerOfTwo(int n)
{
    return (n>0 &&(n&(n-1))==0);
}

bool isPowerOfTwo2(int n)
{
    if(n<0)
        return false;
    if(n==1)
        return true;
    int x=2;
    while(x<n)
    {
        x=x*x;
    }
    return x==n;
}

int main()
{
    int n=6;
    std::cout<<n<<" is power of two: "<<(isPowerOfTwo2(n)?"yes":"no");
    return 0;
}