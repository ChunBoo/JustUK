
#include<iostream>

int numbersOfCut(int n)
{
    if(n==1)
        return 0;
    if(n&1)      //odd case
        return n;
    return n/2;  //even case
}

int main()
{
    std::cout<<numbersOfCut(7);
}