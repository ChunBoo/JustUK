//given a 2-D matrix, which want to return the 
#include<vector>
#include<iostream>

using DT=std::vector<std::vector<int>>;
using DT1=std::vector<int>;
int getValue(DT1& m,int s,int e)
{
    if(s==e)
        return m[s];
    int sz=m.size();
    for(int i=1;i<sz;++i)
        m[i]+=m[i-1];
    return m[e]-m[s];
}

DT prefixSumOfMatrix(DT& m)
{
    int R=m.size(),C=m[0].size();
    if(R==0||C==0)
        return m;
    for(int r=0;r<R;++r)
    {
        for(int c=1;c<C;++c)
        {
            m[r][c]+=m[r][c-1];
        }
    }
    for(int r=1;r<R;++r)
    {
        for(int c=0;c<C;++c)
            m[r][c]+=m[r-1][c];
    }
    return m;
}

int main()
{
    DT1 m1{1,2,3,4,5,6};
    std::cout<<getValue(m1,1,3);
    DT m{{0,1,2},{2,1,4},{3,2,1}};
    DT M=prefixSumOfMatrix(m);
    for(auto r:M)
    {   
        std::cout<<'\n';
        for(auto v:r)
            std::cout<<v<<',';
    }
    return 0;
}