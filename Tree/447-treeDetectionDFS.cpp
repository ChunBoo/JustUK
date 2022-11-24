#include<vector>
#include<unordered_map>
#include<set>
#include<iostream>
#include<algorithm>
using VEC=std::vector<int>;
using MAP=std::unordered_map<int,int>;
using SEEN=std::set<int>;


bool f(const VEC& left, const VEC& right,int cur, SEEN& seen)
{
    if(std::find(seen.begin(),seen.end(),cur)!=seen.end())
        return false;
    seen.insert(cur);
    if(left[cur]!=-1)
    {
        if(!f(left,right,left[cur],seen))
            return false;
    }
    if(right[cur]!=-1)
    {
        if(!f(left,right,right[cur],seen))
            return false;
    }
    return true;
}    

bool detection(const VEC& left, const VEC& right)
{
    int n=left.size();
    MAP data{};
    for(int i=0;i<n;++i)
    {
        if(left[i]!=-1)
            data[left[i]]+=1;
        if(right[i]!=-1)
            data[right[i]]+=1;
    }
    VEC roots{};
    for(int i=0;i<n;++i)
    {
        if(data[i]==0)
            roots.push_back(i);
    }
    if(roots.size()!=1)
        return false;
    int root=roots[0];
    SEEN seen{};
    
    return f(left,right,root,seen) && seen.size()==n;
}

int main()
{
    VEC left{1, -1, 3, -1},right{2, -1, -1, -1};
    std::cout<<detection(left,right);
}