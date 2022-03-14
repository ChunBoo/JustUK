#include<iostream>

long int f(int num)
{
    int ans=1;
    for(int i=2;i<num+1;++i)
        ans*=i;
    return ans;
}

int main()
{
    long res=f(5);
    std::cout<<res;
    return 0;
}