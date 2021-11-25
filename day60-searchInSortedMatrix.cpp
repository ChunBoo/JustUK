//search in a sorted matrix

#include<iostream>
#include<vector>

bool searchInSortedMatrix(std::vector<std::vector<int>>& m,int t)
{
    int rows=m.size();
    int cols=m[0].size();

    int row=0;
    int col=cols-1;

    while(row<rows && col>=0)
    {
        if(t==m[row][col])
            return true;
        else if(t<m[row][col])
            col--;
        else
            row++;
    }
    return false;
}


int main()
{
    std::vector<std::vector<int>> m(3,std::vector<int>(4,0));
    int num=0;
    for(int r=0;r<3;++r)
    {
        for(int c=0;c<4;++c)
        {
            m[r][c]=num++;
        }
    }
    std::cout<<"matrix is:\n";
    for(int r=0;r<3;++r)
    {
        for(int c=0;c<4;++c)
        {
            std::cout<<m[r][c]<<' ';
        }
        std::cout<<'\n';
    }
    int target=13;
    bool foundResult=searchInSortedMatrix(m,target);
    std::cout<<"Can find:"<<target<<" in matrix?"<<(foundResult?"Yes":"No");
    return 0;
}