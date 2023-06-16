#include<vector>
#include<iostream>

using VEC=std::vector<int>;
using MATRIX=std::vector<std::vector<int>>;

using std::cout;


VEC xorQueries(const VEC& arrs, const MATRIX& query)
{
    size_t n=arrs.size();
    VEC xors(n+1,0);
    for(size_t i=0;i<n;++i)
        xors[i+1]=xors[i]^arrs[i];

    VEC ans{};

    for(const auto& lr:query)
    {
        const int  l=lr[0];
        const int r=lr[1];
        ans.push_back(xors[r+1]^xors[l]);
    }
    return ans;
}

int main()
{
  VEC  arr {1,3,4,8};
  MATRIX queries {{0,1},{1,2},{0,3},{3,3}};
  VEC res=xorQueries(arr,queries);
  for(const auto& i:res)
    cout<<i<<',';
}