#include<vector>
#include<iostream>
#include<unordered_map>
#include<queue>
#include<set>
#include<algorithm>
using VEC=std::vector<int>;
using MAP=std::unordered_map<int,int>;
using SET=std::set<int>;
using Q=std::queue<int>;


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
    VEC root{};
    for(int i=0;i<n;++i)  //here can not iterate through the data,but should be go through 0-n-1;
    {
        if(data[i]==0)
            root.push_back(i);
    }
    if(root.size()!=1)
        return false;
    SET seen{};
    Q q{};
    q.push(root[0]);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        if(std::find(seen.begin(),seen.end(),cur)!=seen.end())
            return false;
        seen.insert(cur);
        if(left[cur]!=-1)
            q.push(left[cur]);
        if(right[cur]!=-1)
            q.push(right[cur]);
    }
    return seen.size()==n;
}

int main()
{
    VEC left{1, -1, 3, -1},right{2, -1, -1, -1};
    std::cout<<detection(left,right);
}
