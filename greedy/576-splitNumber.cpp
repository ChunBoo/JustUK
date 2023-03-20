#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using VEC=std::vector<int>;


int splitNumber(int n)
{
    VEC tmp{};
    while(n)
    {
        tmp.push_back(n%10);
        n/=10;
    }
    std::sort(tmp.begin(),tmp.end());

    int s1=0,s2=0;
    int nSize=tmp.size();
    for(int i=0;i<nSize-1;i+=2)
    {
        s1=s1*10+tmp[i];
        s2=s2*10+tmp[i+1];
    }
    cout<<s1<<","<<s2<<'\n';
    return s1+s2;
}

int main()
{
    cout<<splitNumber(1234);
}