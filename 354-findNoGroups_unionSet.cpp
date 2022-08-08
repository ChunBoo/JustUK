#include<set>
#include<iostream>
#include<map>
#include<vector>
#include<string>

using STR=std::string;
using PARENT=std::map<STR,STR>;  // node:parent node
using SIZES=std::map<STR,int>;
using SEEN=std::set<STR>;
using VEC=std::vector<STR>;

class CUnionSet
{
    private:
        SIZES sizes{};
        PARENT parent{};
    
    public:
        STR find(STR s);
        bool unionNode(STR a, STR b);
        int curCount();
};

STR CUnionSet::find(STR s)  //return the parent node in the set
{
    if(parent.find(s)!=parent.end())
        return parent[s];
    if(parent.find(s)==parent.end())
    {
        parent[s]=s;
        sizes[s]=1;
        return s;
    }
    if(s!=parent[s])
    {
        parent[s]=find(parent[s]);
    }
    return parent[s];
}

bool CUnionSet::unionNode(STR a,STR b)  //merge two nodes
{
    STR parA=find(a);
    STR parB=find(b);
    if(parA==parB)
        return false;
    int countA=sizes[parA],countB=sizes[parB];

    if(countA<countB)
    {
        STR tmp=parA;
        parA=parB;
        parB=tmp;
    }

    parent[parB]=parA;
    sizes[parA]+=countB;

    return true;
}

int CUnionSet::curCount()
{
    std::map<STR,STR>::iterator iter=parent.begin();
    STR preParent=iter->second;
    int ans=1;
    for(;iter!=parent.end();++iter)
    {
        if(iter->second!=preParent)
        {
            ans+=1;
            preParent=iter->second;
        }
    }
    return ans;
}

int main()
{
    VEC gs{"ACGT", "ACCT", "AGGT", "TTTT", "TTTG"};

    SEEN g{gs.begin(),gs.end()};

    CUnionSet us{};
    for(auto &gene:g)
    {
        std::vector<char> tmp{'A','C','G','T'};            

        for(int i=0;i<gene.size();++i)
        {
            STR cpyGene=STR(gene.data());
            for(auto c:tmp)
            {
                STR tmp=cpyGene.replace(i,1,1,c);
                if(g.count(tmp)>0)
                {
                    us.unionNode(gene,tmp);
                }
            }
        }   
    }
    std::cout<<us.curCount();
}