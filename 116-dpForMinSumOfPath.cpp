//given a matrix,calculate the minimum sum of nodes
#include<iostream>
#include<vector>
#include<map>
//bottom2Top

int getMinSumOfPathBT(std::vector<std::vector<int>>& nums,int row,int col)
{
    if(nums.empty())
        return 0;
    std::map<std::pair<int,int>,int> nb{};
    int sz=nums.size();
    int ans=0;
    for(int r=sz-2;r>=0;--r)
    {
        int _sz=nums[r].size();
        for(int c=0;c<_sz;++c)
        {
            // if(nb.find(std::pair<int,int>(r,c))!=nb.end())

            nums[r][c]+=std::min(nums[r+1][c],nums[r+1][c+1]);
            // nb[std::pair<int,int>(r,c)]=nums[r][c];
            // nb[std::pair<int,int>(r,c)]+=std::min(nb[std::pair<int,int>(r+1,c)],nb[std::pair<int,int>(r+1,c+1)]);
            
        }
    }
    return nums[0][0];
    // return nb[std::pair<int,int>(0,0)];
}


//top2down
int getCurRowValue(std::vector<std::vector<int>>& nums,int r,int c)
{
    if(r==nums.size()-1)
        return nums[r][c];
    return std::min(getCurRowValue(nums,r+1,c),getCurRowValue(nums,r+1,c+1))+nums[r][c];
}

int getMinSumOfPath(std::vector<std::vector<int>>& nums,int row,int col)
{
    if(nums.empty())
        return 0;
    return getCurRowValue(nums,0,0);
}

int main()
{
    std::vector<std::vector<int>> nums{{1},{2,3},{4,5,6},{7,8,9,10}};
    int res=getMinSumOfPathBT(nums,0,0);
    std::cout<<res<<'\n';
}