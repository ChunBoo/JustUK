#include<vector>
#include<iostream>

using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;

void f(MATRIX& m,VEC cur,int x,int s,int n,int k)
{
    if((cur.size()>k) || s>n)
        return ;
    if((cur.size()==k) && (s==n))
        m.push_back(cur);
    for(int i=x;i<10;++i)
    {
        VEC t{cur.begin(),cur.end()};  //here we should pass one temporary vector 
        t.push_back(i);       
        // cur.push_back(i);
        f(m,t,i+1,s+i,n,k);
    }
}

MATRIX combinationSum(int n,int k)
{
    MATRIX m{};
    if(n>45 || k>9)
        return m;
    VEC cur{};
    f(m,cur,1,0,n,k);
    return m;
}

int main()
{
    MATRIX ans=combinationSum(9,3);
    for(auto &v:ans)
    {
        std::cout<<'\n';
        for(auto &d:v)
            std::cout<<d<<',';
    }
}