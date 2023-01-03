#include<iostream>
#include<vector>
#include<cmath>
using MATRIX=std::vector<std::vector<int>>;
using VEC=std::vector<int>;

//back method
void dfs(int n,int last,VEC cur,MATRIX& res)
{
    if((n%last)==0)
    {

        for(int i=last;i<(int)(std::sqrt(n))+1;++i)
        {
            cur.push_back(i);
            VEC tmp{cur};
            tmp.push_back(n/i);
            res.push_back(tmp);
            dfs(n/i,i,cur,res);
            cur.pop_back();
        }
    }
}

MATRIX getFactors(int n)
{
    MATRIX ans{};
    VEC temp{};
    dfs(n,2,temp,ans);
    return ans;
}

int main()
{
    MATRIX res=getFactors(12);
    for(auto &v:res)
    {
        for(auto &d:v)
        {
            std::cout<<d<<',';
        }
        std::cout<<'\n';
    }
}
