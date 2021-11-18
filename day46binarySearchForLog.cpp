//using binary search to get the value of lg(x)

#include<iostream>
#include<cmath>
int lgValue(int x)
{
    if(x<0)
    {
        std::cout<<"ERROR:X should be positive number.\n";
        return 0;
    }
    if(x<1)
        return (-1)*lgValue(1.0/x);

    int lo=0,hi=x;
    int mid=(lo+hi)/2;

    int cur=std::pow(2,mid);
    while(std::abs(cur-x)>1e-5)
    {
        if(cur>=x)
            hi=mid;
        else
            lo=mid;
        mid=(lo+hi)/2;
        cur=std::pow(2,mid);
    }
    return mid;
}


int main()
{
    int retValue=lgValue(8);
    std::cout<<retValue<<'\n';
    return 0;
}