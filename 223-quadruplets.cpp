
//given for vectors and one target value,pick one element from each vector,
// return the counts of how many combinations that can equal to the target
//use one map to record first two vectors value to reduce the time complexity as O(N^2)
#include<vector>
#include<iostream>
#include<map>
using DT=std::vector<int>;
int quadRuplets_origin(DT& a,DT& b,DT& c,DT& d,int t)
{
    std::map<int,int> m{};
    int ans=0;
    for(int ia=0;ia<a.size();++ia)
    {
        for(int ib=0;ib<b.size();++ib)
            m[a[ia]+b[ib]]+=1;
    }

    for(int ic=0;ic<c.size();++ic)
    {
        for(int id=0;id<d.size();++id)
            ans+=m[t-c[ic]-d[id]];
    }
    return ans;
}
int quadRuplets(DT& a,DT& b,DT& c,DT& d,int t)
{
    std::map<int,int> m{};
    int ans=0;
    for(auto i:a)
    {
        for(auto j:b)
        {
            m[i+j]+=1;
        }
    }
    for(auto dv:d)
    {
        for(auto cv:c)
        {
            ans+=m[t-dv-cv];
        }
    }
    return ans;
}


int main()
{
    DT a{1,2,},b{2,3},c{1,4},d{1,3};
    std::cout<<quadRuplets(a,b,c,d,7);
    return 0;
}