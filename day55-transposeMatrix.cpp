//矩阵转置问题

#include<iostream>
#include<vector>

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& A)
{
    int R=A.size();
    int C=A[0].size();

    std::vector<std::vector<int>> T(C,std::vector<int>(R,0));

    for(int r=0;r<R;++r)
    {
        for(int c=0;c<C;++c)
            T[c][r]=A[r][c];
    }
    return T;
}

void printMatrix(std::vector<std::vector<int>>& T)
{
    for(int i=0;i<T.size();++i)
    {
        for(int j=0;j<T[0].size();++j)
            std::cout<<T[i][j]<<' ';
        std::cout<<'\n';
    }       
}

int main()
{
    // std::cout<<"hhhh";
    std::vector<std::vector<int>> a{{{1,2,3},{4,5,6},{7,8,9}}};
    printMatrix(a);
    std::vector<std::vector<int>> T=transpose(a);
    std::cout<<"After transposing:\n";
    printMatrix(T);
    return 0;
}