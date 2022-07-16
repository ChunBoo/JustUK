//calculate the value of n with the expression of n^2+19n-n!=0
#include<iostream>

long int factorial(int n)
{
    if(n==0 ||n==1)
        return 1;
    // if(n<0)   //this step is unnecessary,as the minimum value of n should be 0, will not be a negative  value
    //     return 0;
    
    return factorial(n-1)*n;
}


int calculateValue()
{
    int x=0;
    while(true)
    {
        if(factorial(x)==(x+2000))
            return x+1;
        else
            x+=1;
    }
}

int main()
{
    // int nVal=calculateValue();
    // std::cout<<nVal<<'\n';
    // return 0;
    int res=factorial(2);
}