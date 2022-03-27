#include<iostream>

int oddNumberOfArrange(int L,int R)
{
    return (R+1)/2-L/2;
}


int main()
{
    std::cout<<oddNumberOfArrange(3,7);
    return 0;
}