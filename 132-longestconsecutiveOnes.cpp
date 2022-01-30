#include<iostream>
#include "treeNode.h"

int longestConsecutiveOnes(int n)
{
    if(n<0)
        return 0;

    int ans=0;
    int ones=0;
    while(n)
    {
        if(n&1)
            ones+=1;
        else
            ones=0;
        if(ones>ans) ans=ones;
        n>>=1;
    }
    return ans;
}

int main()
{
    int res=longestConsecutiveOnes(11);
    std::cout<<res<<'\n';
    return 0;
}