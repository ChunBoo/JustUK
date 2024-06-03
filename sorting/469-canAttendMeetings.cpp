#include<iostream>
#include<vector>
#include<algorithm>

using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;

bool overlap(const VEC& a,const VEC& b)
{
    std::cout<<"debug\n";
    return std::min(a[1],b[1])>std::max(a[0],b[0]);
}

bool canAttend( const MATRIX& m)
{
    int sz=m.size();
    for(int i=0;i<sz;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(overlap(m[i],m[j]))
                return false;
        }
    }
    return true;
}

bool canAttendSort(MATRIX& m)  //can not pass const for std::sort?
{
    int sz=m.size();
    std::sort(m.begin(),m.end(),[](VEC& a,VEC& b) { return (b[0]>a[0]);});
    for(int i=0;i<sz-1;++i)
    {
        if(m[i][1]>m[i+1][0])
            return false;
    }
    return true;
}

int main()
{
    MATRIX m{{7,10},{9,11}};
    // std::cout<<canAttend(m)<<'\n';
    std::cout<<canAttendSort(m);
}