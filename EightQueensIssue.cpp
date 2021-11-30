//N-Queen issue,backtracking algorithm
//DFS
#include<iostream>
#include<vector>
#include<cmath>

bool canPlaceInThisRow(std::vector<int>& curRows,int newRow)
{
    for(int col=0;col<curRows.size();++col)
    {
        int curRow=curRows[col];
        if(std::abs(curRow-newRow)==(curRows.size()-col) || newRow==curRow)
            return false;
    }
    return true;
}

int dfs(std::vector<int>& cur,int row)
{
    if(cur.size()==row)
        return 1;
    int ans=0;
    for(int i=0;i<row;++i)
    {
        if(canPlaceInThisRow(cur,i))
        {
            cur.push_back(i);
            ans+=dfs(cur,i);
        }
    }
    return ans;
}


int Queen(int nums)
{
    std::vector<int> currentRows;
    return dfs(currentRows,nums);
}


int main()
{
    int nums=8;
    int cnts=Queen(nums);
    std::cout<<nums<<" queen has: "<<cnts<<" solutions.\n";
    return 0;
}
