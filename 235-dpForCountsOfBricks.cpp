//top-down dp method to get the total count of bricks  unlimited knapsack
//bricks is [2,3],each bricks width,
// int h is the height of wall
//int w is the total width of each line
//the result is std::pow(countofBricks,h)
#include<iostream>
#include<vector>
#include<cmath>

using DT=std::vector<int>;

int f(const DT& bricks,int w)  //top 2 down method
{
    if(w<0)
        return 0;
    if(w==0)
        return 1;
    int ans=0;
    for(auto v:bricks)
    {
        ans+=f(bricks,w-v);
    }
    return ans;
}

int getCount(const DT& bricks,int width,int height)
{
    return std::pow(f(bricks,width),height);
}





















/*
int f(const std::vector<int>& bricks,int n)
{
    int ans=0;
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    
    for(auto i:bricks)
    {
        ans+=f(bricks,n-i);
    }
    return ans;
}
int countofbricks(const std::vector<int>& bricks,int h,int w)
{
    int ans=f(bricks,w);
    std::cout<<"ans= "<<ans<<'\n';
    return std::pow(ans,h);
}
*/
int main()
{
    std::vector<int> bricks{2,3};
    std::cout<<getCount(bricks,5,6);
    return 0;
}