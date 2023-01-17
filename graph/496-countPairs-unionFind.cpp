#include<iostream>
#include<vector>
#include<map>

using VEC=std::vector<int>;
using MATRIX=std::vector<VEC>;
using G=std::map<int,VEC>;


class DisjointSet
{
    private:
        VEC m_par{};
        VEC m_size{};
    
    public:
        
        DisjointSet(int n)
        {
            for(int i=0;i<n;++i)
            {
                m_par.push_back(i);
                m_size.push_back(1);
            }
        }
        int find(int i)
        {
            if(i!=m_par[i])
            {
                m_par[i]=find(m_par[i]);
            }
            return m_par[i];
        }
        bool merge(int a,int b)
        {
            int pa=find(a),pb=find(b);
            if(pa==pb)
                return false;
            if(m_size[a]<m_size[b])
            {
                int pTmp=pa;
                pa=pb;
                pb=pTmp;
            }
            m_par[pb]=pa;
            m_size[pa]+=m_size[pb];
            m_size[pb]=0;
        }
        int getSize(int a) const 
        {
            return m_size[a];
        }
};

int countPair(int n,const MATRIX& edges)
{
    G g{};

    DisjointSet ds{n};
    int ans=0;
    for(auto &v:edges)
    {
        ds.merge(v[0],v[1]);
    }
    for(int i=0;i<n;++i)
    {
        int c=ds.getSize(i);
        ans+=(n-c)*c;
    }
    return ans/2;
}

int main()
{
        int n = 7;
    MATRIX edges = {{0,2},{0,5},{2,4},{1,6},{5,4}};
    std::cout<<(countPair(n,edges));
}
