#include<iostream>
#include<vector>
#include<set>
using DT=std::vector<std::vector<int>>;
using PAIR=std::pair<int,int>;

void dfs(std::set<PAIR>& seen,DT& image,int r,int c,int newColor)
{
    int R=image.size(),C=image[0].size();

    if(r>=R||c>=C||R==0||C==0)
        return;

    int color=image[r][c];
    if(color==newColor)
        return;
    if(seen.find(PAIR(r,c))!=seen.end())
        return;
    seen.insert(PAIR(r,c));
    image[r][c]=newColor;
    if(r>0&&image[r-1][c]==color) dfs(seen,image,r-1,c,newColor);
    if(c>0&&image[r][c-1]==color) dfs(seen,image,r,c-1,newColor);
    if((r<R-1)&&image[r+1][c]==color) dfs(seen,image,r+1,c,newColor);
    if((c<C-1)&&image[r][c+1]==color) dfs(seen,image,r,c+1,newColor);
}


void FloodFillImage(DT& image)
{
    std::set<PAIR> seen{};
    dfs(seen,image,1,3,2);
}


int main()
{
    DT image{{1,1,2,0},\
             {1,0,2,1},\
             {1,1,0,2},\
             {0,0,3,1}};
    FloodFillImage(image);
    for(auto r:image)
    {
        std::cout<<'\n';
        for(auto v:r)
            std::cout<<v<<',';
    }
    return 0;
}

