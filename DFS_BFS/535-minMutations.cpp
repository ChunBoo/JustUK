#include<iostream>
#include<deque>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using std::cout;
using STR=std::string;
using VEC=std::vector<STR>;
using SET=std::set<STR>;

int minMutations(const STR& s, const STR& e, VEC bank)
{
    std::deque<std::pair<const STR&,int>> q{};
    q.push_back(std::make_pair(s,0));
    STR tmpChars{"AGCT"};
    SET seen{s};
    while(!q.empty())
    {
        std::pair<const STR&,int> cur=q.front();
        q.pop_front();
        if(e==cur.first)
            return cur.second;
        int n=cur.first.size();
        for(int i=0;i<n;++i)
        {
            for(auto &c:tmpChars)
            {
                STR tmpString{cur.first.substr(0,i)+c+cur.first.substr(i+1,n)};
                if(std::find(std::begin(bank),std::end(bank),tmpString)!=std::end(bank) && seen.find(tmpString)==seen.end())
                {
                    seen.insert(tmpString);
                    q.push_back(std::make_pair(tmpString,cur.second+1));
                }
            }
        }
    }
    return -1;
}
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        q.push(startGene);

        unordered_set<string> visited;
        visited.insert(startGene);
        int steps=0;
        while(!q.empty()){
            size_t size=q.size();
            while(size--){
                string curr=std::move(q.front());
                q.pop();
                if(curr==endGene)
                    return steps;
                for(const string& gene:bank){
                    if(visited.count(gene)||!validMutation(curr,gene)) continue;
                    visited.insert(gene);
                    q.push(gene);
                }
            }
            ++steps;
        }
        return -1;
    }
private:
    bool validMutation(const string& s1,const string& s2){
        int count=0;
        for(int i=0;i<s1.length();++i)
            if(s1[i]!=s2[i]&&count++)
                return false;
        return true;
    }
};
int main()
{
    STR s="AACCGGTT",e="AACCGGTA";
    VEC bank{"AACCGGTA"};
    cout<<minMutations(s,e,bank);
}