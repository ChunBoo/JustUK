#include<iostream>

int oddNumberOfArrange(int L,int R)
{
    return (R+1)/2-L/2;
}

int oddNumberOfArrangeWhile(int L,int R)
{
    if(L%2==0)  //EVEN NUMBER
        L+=1;
    int ans=0;
    while(L<=R)
    {
        if(L%2!=0)   //should use val%2!=0 to determine if  val is an odd number
            ans+=1;
        L+=2;
    }
    return ans;
}

int main()
{
    std::cout<<oddNumberOfArrangeWhile(3,9);
    return 0;
}