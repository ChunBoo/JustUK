//check how many zeros in a factorial number,likes,120 will return 1

//method is check the numbers of 5;

#include<vector>
#include<iostream>

int checkZerosInFactorialNumberTail(int n)
{
    int ans=0;
    while(n>0)
    { 
        n/=5;
        ans+=n;
    }
    return ans;
}

int main()
{
    int n=25;
    std::cout<<checkZerosInFactorialNumberTail(n)<<'\n';

    return 0;
}