//top-down dp method to get the total count of bricks 
//bricks is [2,3],each bricks width,
// int h is the height of wall
//int w is the total width of each line
//the result is std::pow(countofBricks,h)


#include<iostream>
#include<vector>
#include<cmath>
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
    return std::pow(ans,h);
}

int main()
{
    std::vector<int> bricks{2,3};
    std::cout<<countofbricks(bricks,6,5);
    return 0;
}