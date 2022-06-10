#include<iostream>
#include<cmath>
bool canJump(int A[],int n)  //greedy method
{
    int reach=0;
    for(int i=0;i<n&&i<=reach;++i)
    {
        reach=std::max(reach,A[i]+i);
    }
    return reach>=n-1;
}

int main()
{
    int a[]{1,1,0};
    std::cout<<canJump(a,3);
}