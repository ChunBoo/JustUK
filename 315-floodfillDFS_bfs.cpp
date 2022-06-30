#include<iostream>
#include<vector>
#include<set>
#include<queue>
using DT=std::vector<std::vector<int>>;
using PAIR=std::pair<int,int>;
using QUEUE=std::queue<PAIR>;
//reference link:https://helloacm.com/the-image-flood-fill-algorithm-c/
void bfs(DT& image,int sr,int sc,int newColor)
{
    int R=image.size(),C=image[0].size();
    if(!R||!C||sc>=C||sr>=R)
        return;
    QUEUE q{};

    q.push(PAIR(sr,sc));   //std::make_pair(sr,sc) also worked
    while(!q.empty())
    {
        auto curPos=q.front();
        q.pop();
        int r=curPos.first,c=curPos.second;
        int color=image[r][c];
        if(color==newColor)
            continue;
        image[r][c]=newColor;
        if(r>0&&image[r-1][c]==color) q.push(PAIR(r-1,c));
        if(c>0&&image[r][c-1]==color) q.push(PAIR(r,c-1));

        if((r<R-1)&&(image[r+1][c]==color)) q.push(PAIR(r+1,c));
        if((c<C-1)&&(image[r][c+1]==color)) q.push(PAIR(r,c+1));
    }

}


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
    // FloodFillImage(image);
    bfs(image,0,0,2);
    for(auto r:image)
    {
        std::cout<<'\n';
        for(auto v:r)
            std::cout<<v<<',';
    }
    return 0;
}

