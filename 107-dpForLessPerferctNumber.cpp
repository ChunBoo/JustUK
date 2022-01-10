//given a number n, use DP for getting the least counts of perfect number


#include<iostream>

int f(int n)
{
    if(n==0)
        return 0;
    
    return std::min(f(n),f(n-))
}