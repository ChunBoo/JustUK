#include<iostream>

int f(int n,int k,int i,int j)
{
    if(j>k)
        return 0;
    if(i==n)
        return 1;
    return f(n,k,i+1,0)+f(n,k,i+1,j+1);
}

int winGames(int n,int k)
{
    return f(n,k,0,0);
}

int main()
{
    std::cout<<winGames(3,2);
}