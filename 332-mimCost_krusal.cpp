#include<iostream>
#include<vector>
#include<algorithm>

using DT=std::vector<std::vector<int>>;
class Solution
{
    public:
        int minCost(int N,DT& connections)
        {
            int totalCost=0;
            std::vector<int> parent(N+1);
            for(int i=0;i<=N;++i)
                parent[i]=i;
            
            std::sort(std::begin(connections),std::end(connections),[](auto &a,auto &b){
                return a[2]<b[2];
                });
            for(const auto &c:connections)
            {
                int x=c[0];
                int y=c[1];
                if(!connected(x,y,parent))
                {
                    union_set(x,y,parent);
                    totalCost+=c[2];
                }
            }
            int c=0;
            for(int i=1;i<=N;++i)
                if(parent[i]==i) c++;

            return c==1?totalCost:-1;
        }

        private:
            bool connected(int x,int y,std::vector<int> &parent)
            {
                return find(x,parent)==find(y,parent);
            }
            int find(int x,std::vector<int>& parent)
            {
                while(x!=parent[x])
                {
                    parent[x]=parent[parent[x]];
                    x=parent[x];
                }
                return x;
            }
            void union_set(int x,int y,std::vector<int> &parent)
            {
                int px=find(x,parent);
                int py=find(y,parent);

                if(px!=py)
                    parent[x]=py;
            }
};

int main()
{
    DT connections{{1,2,5},{1,3,6},{2,3,1}};
    Solution s;
    int res=s.minCost(3,connections);
    std::cout<<res<<'\n';
}