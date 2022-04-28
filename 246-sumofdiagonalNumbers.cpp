//given a matrix, rows and columns count are same,likes 4
//return the sum of numbers in diagonal

#include<vector>
#include<iostream>

using DT=std::vector<std::vector<int>>;
int sumOfDiagonal(const DT& m)
{
    int sz=m.size();
    if(sz==1)
        return m[0][0];
    int ans=0;
    for(int i=0;i<sz;++i)
    {
        ans+=m[i][i];
        int j=sz-i-1;
        if(i!=j)
            ans+=m[j][j];
    }    
    return ans;
}

int sumOfDiagonal2(const DT& m)
{
    int sz=m.size();
    if(sz==1)
        return m[0][0];
    int ans=0;
    for(int i=0;i<sz;++i)
    {
        ans+=m[i][i]+m[sz-i-1][sz-i-1];
    }
    if(sz%2!=0)  //odd number,should remove the m[sz/2][sz/2]
        ans-=m[sz/2][sz/2];
    return ans;
}

int main()
{    
    DT m{{1,2,3,1},\
         {4,5,6,1},\
         {7,8,9,1},\
         {1,2,2,3}};
    std::cout<<sumOfDiagonal2(m);
    return 0;
}