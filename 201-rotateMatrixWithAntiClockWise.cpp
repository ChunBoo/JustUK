
#include<vector>
#include<iostream>

using DT=std::vector<std::vector<int>>;

DT transpose(DT& M)
{
    int R=M.size(),C=M[0].size();
    DT N(C,std::vector<int>(R,0));
    for(int r=0;r<R;++r)
    {
        for(int c=0;c<C;++c)
        {
            N[c][r]=M[r][c];
        }
    }
    return N;
}
DT rotateWithAntiClockWise(DT& M)
{
    
    DT N=transpose(M);
    int sz=M.size();
    for(int r=0;r<sz/2;++r)
    {
        //reverse the lines
        std::vector<int> temp=N[r];
        N[r]=N[sz-r-1];
        N[ sz-r-1]=temp;  
    }
    return N;
}
int main()
{
DT M{{1,2,3},{4,5,6},{7,8,9}};
    for(auto r:M)
    {
        std::cout<<'\n';
        for(auto v:r)
            std::cout<<v<<',';
    }
    std::cout<<"\n-------------\n";
    DT N=rotateWithAntiClockWise(M);
        for(auto r:N)
    {
        std::cout<<'\n';
        for(auto v:r)
            std::cout<<v<<',';
    }
}