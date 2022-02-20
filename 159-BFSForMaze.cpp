// maze using BFS solution
#include<set>
#include<iostream>
#include<vector>
#include<deque>
using MATRIX=std::vector<std::vector<int>>;
using PAIR=std::pair<int,int>;
using SUBVEC=std::vector<int>;
int BFS4Maze(MATRIX nums)
{
    int rows=nums.size();
    int cols=nums[0].size();

    if((nums[0][0]==1) || (nums[rows-1][cols-1]==1))
        return -1;

    std::set<PAIR> seen;
    std::deque<std::pair<PAIR,int>> q;
    q.push_back(std::pair<PAIR,int>(PAIR(0,0),0));
    std::vector<PAIR> Dir{PAIR(0,1),PAIR(1,0),PAIR(-1,0),PAIR(0,-1)};
    while(!q.empty())
    {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int distance=q.front().second;
        q.pop_front();
        if((r==rows-1)&&(c==cols-1))
            return distance;
        if(seen.find(PAIR(r,c))!=seen.end())
            continue;
        seen.insert(PAIR(r,c));
        for(auto d:Dir)
        {
            int nr=d.first+r;
            int nc=d.second+c;
            if( (nr>=0&&nr<=rows-1) && (nc>=0&&nc<=cols-1) && nums[nr][nc]!=1)
                q.push_back(std::pair<PAIR,int>(PAIR(nr,nc),distance+1));
        }
    }
    return -1;
}

int main()
{
    MATRIX nums{SUBVEC{0,0,1,0,0},\
                SUBVEC{1,0,0,0,0},\
                SUBVEC{0,0,0,1,0},\
                SUBVEC{1,1,0,1,0}};
    int d=BFS4Maze(nums);
    std::cout<<d<<'\n';
    return 0;
}