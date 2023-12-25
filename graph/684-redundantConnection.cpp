#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph;
        for(const auto& edge:edges){
            int u=edge[0];
            int v=edge[1];

            unordered_set<int> visited;
            if(hasPath(u,v,graph,visited))
                return edge;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }

private:
    bool hasPath(int cur,
                 int goal,
                 const unordered_map<int,vector<int>>& graph,
                 unordered_set<int>& visited){
        if(cur==goal) return true;
        visited.insert(cur);
        if(!graph.count(cur)||!graph.count(goal)) return false;
        for(int nxt:graph.at(cur)){
            if(visited.count(nxt)) continue;
            if(hasPath(nxt,goal,graph,visited)) return true;
        }
        return false;
    }
};

class Solution2 {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       vector<int> parents(edges.size()+1,0);
       vector<int> sizes(edges.size()+1,1);

       for(const auto& edge:edges){
           int u=edge[0];
           int v=edge[1];
           if(!parents[u]) parents[u]=u;
           if(!parents[v]) parents[v]=v;
           int pu=find(u,parents);
           int pv=find(v,parents);

           if(pu==pv) return edge;
           if(sizes[pv]>sizes[pu])
            swap(pu,pv);
           parents[pv]=pu;
           sizes[pu] += sizes[pv];
       }
       return {};
        }

private:
   int find(int node,vector<int>& parents){
       while(parents[node]!=node){
           parents[node]=parents[parents[node]];
           node=parents[node];
       }
       return node;
   }
};



class UnionFindSet{
public:
    UnionFindSet(int n)
    {
        parent_=vector<int>(n+1,0);
        rank_=vector<int>(n+1,0);
        for(int i=0;i<parent_.size();++i)
            parent_[i]=i;
    }
    int find(int x)
    {
        if(x!=parent_[x])
            parent_[x]=find(parent_[x]);
        return parent_[x];
    }
    bool _union(int x,int y)
    {
        int px=find(x),py=find(y);
        if(px==py)
            return false;
        if(rank_[px]<rank_[py]) parent_[px]=py;
        if(rank_[px]>rank_[py]) parent_[py]=px;
        if(rank_[px]==rank_[py]){
            parent_[px]=py;
            ++rank_[px];
        }
        return true;
    }

private:
    vector<int> parent_;
    vector<int> rank_;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFindSet us=UnionFindSet(edges.size());
        for(const auto& e:edges)
        {
            if(!us._union(e[0],e[1]))
                return e;
        }
        return {};
    }
};
int main() {
  vector<vector<int>> edges{{1, 2}, {2, 3}, {1, 3}};
  vector<int> res = Solution().findRedundantConnection(edges);
  vector<int> res2 = Solution2().findRedundantConnection(edges);

  for (auto v : res)
    cout << v << ',';
  cout << '\n';
  for (auto v : res2)
    cout << v << ',';
}