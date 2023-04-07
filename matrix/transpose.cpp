#include<vector>
#include<iostream>

using std::cout;
using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;


void transpose(MATRIX& m)
{
    int R=m.size();
    for(int r=0;r<R;++r)
    {
        for(int c=0;c<r;++c)
        {
            int tmp=m[r][c];
            m[r][c]=m[c][r];
            m[c][r]=tmp;
        }
    }
}

int main()
{
    MATRIX m{{1,2,3},{4,5,6},{7,8,9}};
    transpose(m);
    for(auto &_v:m)
    {
        for(auto &v:_v)
            cout<<v<<',';
        cout<<'\n';
    }
}