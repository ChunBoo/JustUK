#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using VEC=std::vector<int>;
using MATRIX=std::vector<const VEC>;
using MAP=std::map<double,int>;

double dis(const VEC& a, const VEC& b)
{
    return std::sqrt(std::pow(a[0]-b[0],2)+std::pow(a[1]-b[1],2));
}

bool validSquare(const VEC& p1, const VEC& p2, const VEC& p3, const VEC& p4)
{
    MATRIX arr{p1,p2,p3,p4};  //https://stackoverflow.com/questions/39800847/c-vector-allocator-error
    MAP d{};
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<i;++j)
        {
            double dd=dis(arr[i],arr[j]);
            d[dd]+=1;
        }
    }
    return (d.size()==2) && d[0]==0;
}

int main()
{
    VEC p1 = {0,0};
    VEC p2 = {1,1};
    VEC p3 = {1,0};
    VEC p4 = {0,2};
    bool res=validSquare(p1,p2,p3,p4);
    std::cout<<res;
}