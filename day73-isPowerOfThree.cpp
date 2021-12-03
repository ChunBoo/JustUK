// check if a number is a power of 3,using bf
#include<iostream>


bool isPowerOfThree(int n)
{
    if(n<=0)
        return false;
    if(n==1)
        return true;
    
    int l=0,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int cur=mid*mid*mid;
        if(cur==n)
            return true;
        if(cur<n)
            l=mid+1;
        else
            r=mid-1;
    }
    return false;
}

int main()
{
    int n=3;
    std::cout<<isPowerOfThree(n)<<'\n';
    return 0;
}