#include<iostream>
#include<vector>

using DT=std::vector<std::vector<int>>;

int dfs(DT& M,int r,int c,int rows,int cols)
{
  if(r<0||r>=rows||c<0||c>=cols)
    return 0;
  
  if(M[r][c]==0)
    return 0;
  M[r][c]=0;//this step is important and necessary,otherwise it will dead-loop and segfault
  dfs(M,r-1,c,rows,cols);
  dfs(M,r+1,c,rows,cols);
  dfs(M,r,c-1,rows,cols);
  dfs(M,r,c+1,rows,cols);
  return 1;
}

int getIslands(DT& M)
{
  

  if(M.empty())
    return 0;
  int ans=0;
  int R=M.size(),C=M[0].size();
  for(int r=0;r<R;++r)
  {
    for(int c=0;c<C;++c)
    {
      ans+=dfs(M,r,c,R,C);
    }
  }
  return ans;
}

int main()
{
    DT M={{1,1,0,0},\
        {0,1,0,0},\
        {0,0,1,1},\
        {1,0,0,0}};
    std::cout<<getIslands(M);
    return 0;
}
