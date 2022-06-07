#include<iostream>
#include<cmath>
bool canJump(int A[],int n)
{
    int i=0;
    for(int reach=0;i<n&&i<=reach;++i)
        reach=std::max(i+A[i],reach);
    return i==n;
}

int main()
{
    int a[]{2,3,1,1,0,4};
    std::cout<<canJump(a,6);
}