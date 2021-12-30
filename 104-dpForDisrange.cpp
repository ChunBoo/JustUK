//dp method of getting all of the disarrange
//given a number, such as 3, get it's count of disarrange 
//f(1)=0,f(2)=1,f(3)=(3-1)(f(0)+f(1))=2*1=2,...,f(n)=(n-1)(f(n-2)+f(n-1))
#include<map>
#include<iostream>

long long dpForDisarrange(int val)
{
    if(val<=1)
        return 0;
    if(val==2)
        return 1;
    
    std::map<long,long long> dp{};

    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<val+1;++i)
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);

    return dp[val];
}

int main()
{
    int val=13;
    long long res=dpForDisarrange(val);
    std::cout<<"When value is "<<val<<" ,we have "<<res<<" disarrange.\n";
    return 0;

}