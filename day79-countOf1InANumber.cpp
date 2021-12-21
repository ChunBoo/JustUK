//return how many one in a number with binary format

#include<iostream>

int countOfOne2(int n)
{
    int ans=0;
    while(n>0)
    {

        ans+=(n&1);
        n>>=1;
    }
    return ans;
}

int countOfOne(int n)
{
    int ans=0;
    while(n>0)
    {
        ans+=1;
        n=n&(n-1);  //这里与上面差别比较大
    }
    return ans;
}

int main()
{
    int n=15;
    int ret=countOfOne(n);
    std::cout<<"Result is:"<<ret<<'\n';
    return 0;
}