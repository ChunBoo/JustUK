#include<iostream>

bool isThreeDivisors(int n )
{
   if(n==1||n==2)
    return false;

   int c=2,i=2;
   while(i*i<=n)
   {
       if(n%i==0)
       {
           c+=1;
           if(n*n<n)
            c+=1;
       }
       i+=1;
   }
   return c;
}

int main()
{
    std::cout<<isThreeDivisors(6);
    return 0;
}