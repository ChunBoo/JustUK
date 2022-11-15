#include<iostream>
// #include<math>
int fact(int n)   //factorial is n!=1*2*3*4****n
{
     return (n==0) || (n==1) ? 1 : n* fact(n-1);
}
int f(int n,int k)
{
    if(n<k)
        return 0;
    if(k==1)
        return fact(n-1);
    if(k==n)
        return 1;

    return f(n-1,k-1)+(n-1)*f(n-1,k);
}

int main()
{
    std::cout<<f(4,2);
}