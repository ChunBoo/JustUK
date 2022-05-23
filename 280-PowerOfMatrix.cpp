
#include<iostream>
#include<vector>
#include "arithmeticOperationsOfMatrix.h"
using DT=std::vector<std::vector<int>>;

DT pow(DT& a,int n)
{
    int R=a.size(),C=a[0].size();
    if(R<1||R!=C)
        return DT{};
    
    DT ans(R,std::vector<int>(C,0));
    for(int i=0;i<R;++i)
        ans[i][i]=1;

    while(n>0)
    {
        if(n&1)
        {
            ans=multiplyMatrix(ans,a);
        }
        n>>=1;
        a=multiplyMatrix(a,a);
    }
    return ans;
}

int main()
{
    DT a{{1,2},\
         {3,4}};
    DT res=pow(a,2);
    for(auto &i:res)
    {
        std::cout<<'\n';
        for(auto v:i)
            std::cout<<v<<',';
    }
    return 0;
}