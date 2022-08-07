

#include<set>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using STR=std::string;
using SEEN=std::set<STR>;
using VEC=std::vector<STR>;
using QUE=std::queue<STR>;
void bfs(const STR& gene,SEEN& g)
{
    QUE q{};
    q.push(gene);
    while(!q.empty())
    {
        for(int i=0;i<gene.size();++i)
        {
            STR cur=q.front();

            std::vector<char> CHARS{'A','G','C','T'};
            for(auto c:CHARS)
            {
                STR tmp=cur.replace(i,1,1,c);
                if(g.find(tmp)!=g.end())
                {
                    g.erase(tmp);
                    q.push(tmp);
                }
            }
        }
        q.pop();

    }
}


int geneMutationGroup(const VEC& genes)
{
    std::set<STR> g{genes.begin(),genes.end()};
    int ans=0;
    for(auto &n:genes)
    {
        if(g.count(n)>0)
        {
            ans++;
            bfs(n,g);
        }
    }
    return ans;
}


int main()
{
    VEC gs{"ACGT", "ACCT", "AGGT", "TTTT", "TTTG"};
    std::cout<<geneMutationGroup(gs);
    return 0;
}