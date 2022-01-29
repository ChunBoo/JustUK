#include<iostream>

int longestConsecutiveOnes(int n)
{
    int ans=0;
    int max=0;
    while(n>0)
    {
        if(n&1)
        {
            max+=1;
        }
        else
        {
            if(ans<max) ans=max;
            max=0;
        }
        n>>=1;
    }
    if(ans<max) ans=max;
    return ans;
}

int main()
{
    int res=longestConsecutiveOnes(1);
    std::cout<<res<<'\n';
    return 0;
}