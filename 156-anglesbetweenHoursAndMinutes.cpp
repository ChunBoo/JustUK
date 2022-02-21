//given  the hours and minutes,to calculate the angles difference

#include<iostream>
#include<cmath>
float getAngles(int hrs,float minuts)
{
    int hr=hrs%12;
    float h=(hr+minuts/60)*30;
    float m=minuts*6;
    float ans=std::abs(h-m);
    return std::min(ans,360-ans);
}

int main()
{
    int h=3,m=30;
    std::cout<<getAngles(h,m);
    return 0;
}