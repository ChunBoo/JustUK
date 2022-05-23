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