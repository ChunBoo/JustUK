//given a array, return the max product value of two elements

#include<vector>
#include<iostream>
#include<algorithm>

using DT=std::vector<int>;

int maxProduct2(DT& list)
{
    if(list.empty())
        return 0;
    int B1=INT_MIN,B2=INT_MIN;
    int S1=INT_MAX,S2=INT_MAX;

    for(auto i:list)
    {
        if(i>B1)
        {
            B2=B1;
            B1=i;
        }
        else if(i>B2)
        {
            B2=i;
        }
        if(i<S1)
        {
            S2=S1;
            S1=i;
        }
        else if(i<S2)
        {
            S2=i;
        }
    }
    return std::max(S1*S2,B1*B2);
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
    DT l={-100,-2,-1,4,55};
    std::cout<<maxProduct2(l);
    return 0;
}