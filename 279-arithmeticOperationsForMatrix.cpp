#include<iostream>
#include<vector>
#include "arithmeticOperationsOfMatrix.h"


DT multiplyMatrix(const DT& a, const DT& b)
{
    int R=a.size();
    int C=b[0].size();
    DT ans(R,std::vector<int>(C,0));  //there is inside std::vector<int>
    for(int i=0;i<R;++i)
    {
        for(int j=0;j<C;++j)
        {
            for(int k=0;k<C;++k)
            {
                ans[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return ans;
}

int main()
{
    DT a{{1,2},{3,4}},b{{1,1},{1,1}};
    DT ret=multiplyMatrix(a,b);
    for(auto &d:ret)
    {
        std::cout<<'\n';
        for(auto i:d)
            std::cout<<i<<',';
    }
    return 0;
}