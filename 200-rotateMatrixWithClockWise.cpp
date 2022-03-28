//rotate one matrix as 45 degree

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


DT rotateMatrix45Degree(DT& M)
{
    DT N=transpose(M);
    int R=N.size(),C=N[0].size();
    //swap each line
    for(int r=0;r<R;++r)
    {
        int s=0,end=N[r].size()-1;
        while(s<end)
        {
            int tmp=N[r][s];
            N[r][s]=N[r][end];
            N[r][end]=tmp;
            s+=1;
            end-=1;
        }
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
    DT N=rotateMatrix45Degree(M);
        for(auto r:N)
    {
        std::cout<<'\n';
        for(auto v:r)
            std::cout<<v<<',';
    }
}