#include<vector>
#include<iostream>
#include<algorithm>
using std::cout;
using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;

int findMinArrowShots(MATRIX& m)
{
    int ans=1;
    std::sort(m.begin(),m.end(),[](VEC a,VEC b){return a[1]<b[1];});   //lambda function for sorting the matrix
    int end=m[0][1],n=m.size();
    for(int i=1;i<n;++i)
    {
        if(end<m[i][0])
        {
            ans+=1;
            end=m[i][1];
        }
    }
    return ans;

}

int main()
{
    MATRIX m{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout<<findMinArrowShots(m);
}