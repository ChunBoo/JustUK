#include<iostream>
#include<vector>
#include<cmath>

using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;
using std::cout;


int surfaceA(const MATRIX& g)
{
    int ans=0;
    int n=g.size();
    for(int r=0;r<n;++r)
    {
        for(int c=0;c<n;++c)
        {
            if(g[r][c]>0)
            {
                ans+=(g[r][c]*4+2);
            }
            if(r>0)
                ans-=(std::min(g[r][c],g[r-1][c])*2);
            if(c>0)
                ans-=(std::min(g[r][c],g[r][c-1])*2);
        }
    }
    return ans;
}

int main()
{
    MATRIX g{{1,2},{3,4}};
    cout<<surfaceA(g);
}