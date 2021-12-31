// get two integers products without *,/,>>,<< operators 
#include<iostream>

int productWithWhile(int a,int b)
{
    if(!a||!b)
        return 0;
    if(a<0&&b<0)
        return productWithWhile(-a,-b);
    if(a<b)
        return productWithWhile(b,a);
       
    int i=0;
    int sum=0;
    while(i<a)
    {
        sum+=b;
        i++;
    }
    return sum;
}


int twoIntegersProduct(int a,int b)
{
    if(!a||!b)
        return 0;
    if(a<0&&b<0)
        return twoIntegersProduct(-a,-b);
    if(a<0)
        return twoIntegersProduct(-a,b);
    if(b<0)
        return twoIntegersProduct(a,-b);
    if(a>b)
        return twoIntegersProduct(b,a);

    return twoIntegersProduct(a-1,b)+b;
}

int main()
{
    int a=6,b=-5;
    int flag=1;//(a>0&&b>0||(a<0&&b<0))?1:-1;
    int res=flag*productWithWhile(a,b);
    std::cout<<a<<"*"<<b<<'='<<res<<"\n";
    return 0;
}