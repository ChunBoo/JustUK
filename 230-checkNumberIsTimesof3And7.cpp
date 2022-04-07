//given a number ,return it is multiple  of 3 and 7

#include<iostream>

bool checkTimes(int n)
{
    if(n<=0)
        return false;
    if(n%3==0)
        return true;
    if(n%7==0)
        return true;
    return checkTimes(n-3)||checkTimes(n-7);  //dp for top-down
}

bool f(int n)
{
    int sz=n/3+1;
    for(int i=0;i<sz;++i)
    {
        if((n-3*i)%7==0)
            return true;
    }
    return false;
}

int main()
{
    // std::cout<<checkTimes(11);
    std::cout<<f(10);
    return 0;
}