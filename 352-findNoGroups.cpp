#include<set>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using STR=std::string;
using SEEN=std::set<STR>;
using VEC=std::vector<STR>;
// values ['ACGT', 'GCGT', 'TCGT', 'CCGT', 'AAGT', 'AGGT', 'AGGT', 'GGGT', 'TGGT', 'CGGT', 'AAGT', 'AGGT', 'ATGT', 'ACGT', 'AGAT', 'AGGT', 'AGTT', 'AGCT', 'AGGA', 'AGGG', 'AGGT', 'AGGC',//
//         'ATGT', 'ACGT', 'ACAT', 'ACGT', 'ACTT', 'ACCT', 'ACCT', 'GCCT', 'TCCT', 'CCCT', 'AACT', 'AGCT', 'ATCT', 'ACCT', 'ACAT', 'ACGT', 'ACTT', 'ACCT', 'ACCA', 'ACCG', 'ACCT', 'ACCC', 
//          'ACGA', 'ACGG', 'ACGT', 'ACGC', 'ATTT', 'GTTT', 'TTTT', 'CTTT', 'TATT', 'TGTT', 'TTTT', 'TCTT', 'TTAT', 'TTGT', 
//         'TTTT', 'TTCT', 'TTTA', 'TTTG', 'ATTG', 'GTTG', 'TTTG', 'CTTG', 'TATG', 'TGTG', 'TTTG', 'TCTG', 'TTAG', 'TTGG', 'TTTG', 'TTCG', 'TTTA', 'TTTG', 'TTTT', 'TTTC', 'TTTT', 'TTTC']
void dfs(SEEN &dna, STR& s, SEEN& seen)
{
    if(seen.find(s)==seen.end())
        seen.insert(s);
    std::vector<char> CHARS{'A','G','C','T'};
    for(int i=0;i<s.size();++i)
    {
        STR str=STR(s.data());

        for(char c:CHARS)
        {
            STR newGene=str.replace(i,1,1,c);
            std::cout<<newGene<<',';
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