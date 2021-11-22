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
    std::vector<std::vector<int>> allVal{};
    std::vector<int> val{};
    for(int row=1;row<8;row++)
    {
        for(int col=1;col<=row;++col)
        {
            
            val.push_back(pascalTriangle(row,col));
        }
        allVal.push_back(val);
        val.clear();
    }
    for(int i=0;i<allVal.size();++i)
    {
        for(auto v:allVal[i])
            std::cout<<v<<' ';
        std::cout<<'\n';
    }
    return 0;
}