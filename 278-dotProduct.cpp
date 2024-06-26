//dot product
//a=[1,2,3],b=[4,5,6]--->a.b=1*4+2*5+3*6=4+10+18=34

#include<vector>
#include<iostream>

using DT=std::vector<int>;
int dotProduct(const DT& a, const DT& b)
{
    int n=a.size();
    if(n!=b.size())
    {
        return -1;
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=a[i]*b[i];
    }
    return ans;
}

int main()
{
    DT a{1,2,3},b{4,5,6};
    std::cout<<dotProduct(a,b);
    return 0;
}