#include<set>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using STR=std::string;
using SEEN=std::set<STR>;
using VEC=std::vector<STR>;

void dfs(SEEN &dna, STR s, SEEN& seen)
{
    seen.insert(s);
    STR tmp{"AGCT"};
    for(int i=0;i<s.size();++i)
    {
        for(char c:tmp)
        {
            STR newGene=s.replace(i,1,1,c);
            // std::cout<<newGene<<',';
            // std::seen<STR>::iterator iter=std::find(dna.begin(),dna.end(),newGene);
            if(seen.find(newGene)==seen.end() && dna.find(newGene)!=dna.end())
            {
                dfs(dna,newGene,seen);
            }
        }
    }
}

int countOfMutationGeneGroup(const VEC &Genes)
{
    SEEN seen{};
    std::set<STR> dna{Genes.begin(),Genes.end()};
    int ans=0;
    for(auto g:Genes)
    {
        if(seen.find(g)==seen.end())
        {
            ans+=1;
            dfs(dna,g,seen);
        }
    }
    return ans;
}

int main()
{
    VEC gs{"ACGT", "ACCT", "AGGT", "TTTT", "TTTG"};
    std::cout<<countOfMutationGeneGroup(gs);
    return 0;
}