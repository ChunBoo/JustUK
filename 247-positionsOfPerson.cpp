#include<iostream>
//given n people, at least a persons in the front, and at most b persons in the back
int countOfPositions(int n,int a,int b)
{
    int i=0,ans=0;
    while(i<=b && i<n-a)
    {
        ++i;
        ++ans;
    }

    return ans;
}

int main()
{
    std::cout<<countOfPositions(3,1,1);
    return 0;
}