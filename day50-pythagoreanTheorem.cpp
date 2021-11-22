// pythagoream theorem  
//given the value of c,print all of the pairs of <a,b>


#include<iostream>
#include<cmath>

void printValues(int c)
{
    if(c<=0)
        std::cout<<"Wrong value of C.\n";
    int a{1};
    
    while(c*c>=2*a*a)
    {
        int b2=c*c-a*a;
        int b=static_cast<int>(std::sqrt(b2));
        if(b*b==b2)
        {
            std::cout<<a<<"*"<<a<<" + "<<b<<"*"<<b<<" = "<<c<<"*"<<c<<'\n';
        }
        a+=1;
    }
}


int main()
{
    printValues(100);
    return 0;
}