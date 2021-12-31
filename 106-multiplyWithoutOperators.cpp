// 不用乘除号及移位运算计算两个数乘法
#include<iostream>

int mul(int a,int b)
{
    if(a==0||b==0)
        return 0;
    if(a<0&&b<0)
        return mul(-a,-b);
    if(a<0)
        return mul(-a,b);
    // if(b<0)
    //     return mul(a,-b);
    
    if(a>b)
        return mul(b,a);
    return mul(a-1,b)+b;
}

int main()
{
    int a=-3,b=-5;
    int flag=(a>0&&b>0||(a<0&&b<0))?1:-1;
    int res=flag*mul(a,b);
    std::cout<<a<<"*"<<b<<'='<<res<<"\n";
    return 0;
}