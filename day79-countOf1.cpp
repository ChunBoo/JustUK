//given a integer,return the 1 in this number with binary format


#include<iostream>

int count1(int n)
{
    int ans=0;
    while(n)
    {
        ans+=1;
        n=n&(n-1);
    }
    return ans;
}

int main()
{
    int n=128;
    std::cout<<"There are: "<<count1(n)<<"\n";
    return 0;
}