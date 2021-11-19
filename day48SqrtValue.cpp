//using bs to compute the sqrt(x)
#include<iostream>
#include<cmath>
float mySqrt(float x)
{
    if(x<0)
    {
        std::cout<<"X value is error,should be positive.\n";
        return 0;
    }
    float lo=0,hi=0;
    if(x<1)
        hi=1;
    else
        hi=x;
    float mid=(lo+hi)/2.0;
    float cur=mid*mid;
    while(std::abs(cur-x)>1e-5)
    {
 
        if(cur<=x)
            lo=mid;
        else
            hi=mid;
       mid=(lo+hi)/2.0;
        cur=mid*mid;
    }
    return mid;
}

int main()
{

    float x=2;
    float retValue=mySqrt(x);
    std::cout<<"result: "<<retValue<<'\n';
    return 0;
}