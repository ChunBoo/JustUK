#include<iostream>
#include<vector>
#include<limits>
using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;
// const int inf=std::numeric_limits<int>::max();

// https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
using std::cout;

int shortestDistance(const VEC& d,int s,int e)
{
    const int INF=0X3F3F3F;
    int n=d.size();
    MATRIX D(n,VEC(n,INF));  //can not set the default value as INT_MAX, as it will be overflow....

    for(int i=0;i<n-1;++i)
    {
        D[i][i+1]=D[i+1][i]=d[i];
    }
    D[0][n-1]=D[n-1][0]=d[n-1];

    for(int k=0;k<n;++k)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
                 D[i][j]=std::min(D[i][j],D[k][j]+D[i][k]);
        }
    }
    return D[s][e];
}

int main()
{
    VEC distance={111,12,3,4};
    int start=0,stop=1;
    cout<<shortestDistance(distance,start,stop);
}