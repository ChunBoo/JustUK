class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto e:edges)
        {
            g[e[1]].push_back(e[0]);
        }

        vector<int> node(n,0);//0: not visited, 1:visited
        vector<vector<int>> ans(n);

        for(int i=0;i<n;++i)
        {
            ranges::fill(node, false);
            dfs(g,i,node);
            node[i]=false;
            for(int j=0;j<n;j++)
                if(node[j])
                    ans[i].push_back(j);
        }
        return ans;

    }
private:
    void dfs(const vector<vector<int>>& g, int cur,  vector<int>& node)
    {
        node[cur]=1;
        for(int i:g[cur])
            if(!node[i])
                dfs(g,i,node);
    }
};