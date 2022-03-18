//given a position of chess,return the minimum moves to the target(0,0)
//topDown

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using DT=std::vector<std::vector<int>>;
int f(int x,int y)
{
    if(x<0||y<0)
        return 0;
    if(x==0&&y==0)
        return 0;
    DT fixedPos{{1,1,},{0,2},{2,0}};
    std::vector<int> temp{x,y};
    if(std::find(fixedPos.begin(),fixedPos.end(),temp)!=fixedPos.end())
        return 2;
    return std::min(f(x-1,y-2),f(x-2,y-1))+1;
}

int main()
{
    int x=1,y=0;
    std::cout<<f(x,y);
    return 0;
}