//given a array, return the max product value of two elements

#include<vector>
#include<iostream>
#include<algorithm>

using DT=std::vector<int>;

int maxProduct2(DT& list)
{
    int biggest=INT_MIN, sBig=INT_MIN;
    int smallest=0,sSmall=0;
    for(auto i:list)
    {
        if(i>biggest)
        {
            sBig=biggest;
            biggest=i;
        }
        else if (i>sBig)
        {
            sBig=i;
        }
        if (i<smallest)   //NOTE here is not else if
        {
            sSmall=smallest;
            smallest=i;
        }
        else if(i<sSmall&&i>smallest)
        {
           sSmall=i; 
        }
    }
    return std::max(biggest*sBig,smallest*sSmall);
}


int maxProduct(DT& list)
{
    // int ans=INT_MIN;
    if(list.empty())
        return 0;
    int sz=list.size();
    std::sort(list.begin(),list.end());
    return std::max(list[0]*list[1],list[sz-2]*list[sz-1]);
}

int main()
{
    DT l={-100,-3,-1,4,55};
    std::cout<<maxProduct2(l);
    return 0;
}