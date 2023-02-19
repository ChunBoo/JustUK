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

int main()
{
    STR s="AACCGGTT",e="AACCGGTA";
    VEC bank{"AACCGGTA"};
    cout<<minMutations(s,e,bank);
}