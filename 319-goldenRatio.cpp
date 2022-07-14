#include<iostream>

double goldenRatio(int range)
{
    double  a=1,b=1;  //if the type of a/b is integer will be returned incorrect results
    for(int i=0;i<range;++i)
    {
        double tmp=a+b;
         a=b;
        b=tmp;
    }
    return double(b)/a;
}


int main()
{
    std::cout<<goldenRatio(1000);
    return 0;
}