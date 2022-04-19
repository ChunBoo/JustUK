//given one number,return the hamming length,or the one in it's binary format

#include<iostream>

int hammingLen(int n)
{
    int ans=0;
    while(n)
    {
        ans+=1;
        n&=(n-1);
    }
    return ans;
}

int hammingLength(int n)
{
    int ans=0;
    while (n)
    {
        ans+=n&1;
        n>>=1;
    }
    return ans;    
}

int main()
{
    std::cout<<hammingLength(11);
    return 0;
}