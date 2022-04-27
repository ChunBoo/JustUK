#include<iostream>

bool isThreeDivisors(int n )
{
    if(n<3)
        return false;
    int c=2,i=2;
    while(i*i<=n)
    {
        if(n%i==0)
         {
            c+=1;
            if(i*i!=n)
                c+=1;
            if(c>3)
                return false;
         }
        i+=1;
    }
    return c==3;
}

int main()
{
    std::cout<<isThreeDivisors(6);
    return 0;
}