//given a number ,return it is multiple  of 3 and 7

#include<iostream>

bool checkMultiple(int n)
{
    if(n<0)
      return false;
    if(n%3==0)
      return true;
    if(n%7==0)
      return true;
    return checkMultiple(n-3) || checkMultiple(n-7);
}

bool f(int n)   //iterator method
{
    for(int i=0;i<n/7+1;++i)
    {
        if((n-7*i)%3==0)
            return true;
    }
    return false;
}

int main()
{
    std::cout<<checkMultiple(10);
    std::cout<<'\n'<<f(10);
    return 0;
}