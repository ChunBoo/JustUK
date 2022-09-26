#include<vector>
#include<iostream>
#include<set>


using MATRIX=std::vector<std::vector<int>>;

bool checkMatrix(MATRIX& m)
{
    int sz=m.size();
    int C=m[0].size();
    int x=0;
    for(int i=1;i<sz+1;++i)
        x^=i;
    
    for(int r=0;r<sz;++r)
    {
        int rr=x,cc=x;
        for(int c=0;c<C;++c)
        {
            rr^=m[r][c];
            cc^=m[c][r];
        }
        if(rr||cc)
            return false;
    }
    return true;
}

int main()
{
    MATRIX m{{1,2,3},\
             {3,1,2},\
             {2,3,2}};

    std::cout<<checkMatrix(m);
}