#include<iostream>
#include<cmath>
int getValues()
{
    int l=1,h=2048;
    long long target=std::pow(2,2048);
    while(l<=h)
    {
        int m=(l+h)/2;
        long long unsigned mm=std::pow(m,m);
        if(mm==target)
            return m;
        if(mm>target)
            h=m-1;
        else
            l=m+1;
    }
    return -1;
}

int main()
{
    std::cout<<getValues();
}