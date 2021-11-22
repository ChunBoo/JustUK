#include<iostream>
#include<vector>


int pascalTriangle(int row,int col)
{
    if(row==1 || col==1 ||row==col)
        return 1;
    return pascalTriangle(row-1,col)+pascalTriangle(row-1,col-1);
}


int main()
{
    std::vector<int> val{};
    for(int i=0;i<8;i++)
        for(int j=0;i<i;++j)
        {
            val.push_back(pascalTriangle(i,j));
        }
    
    for(auto i:val)
    {
        std::cout<<i<<' ';
    }
    return 0;
}