#include<iostream>

long int f(int num)
{
    int ans=1;
    for(int i=2;i<num+1;++i)
        ans*=i;
    return ans;
}

long int f1(int num)
{
    return num==0?1:f1(num-1)*num;
}

int main()
{
    long res=f1(5);
    std::cout<<res;
    return 0;
}