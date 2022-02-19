//given  the hours and minutes,to calculate the angles 

#include<iostream>
#include<cmath>
int getAngles(int hrs,float minuts)
{
    int hr=hrs%24;
    int h=(hr+minuts/60)*30;
    int m=minuts*360/60;

    int ans=std::abs(h-m);
    return std::min(ans,360-ans);
}

int main()
{
    int h=3,m=30;
    std::cout<<getAngles(h,m);
    return 0;
}