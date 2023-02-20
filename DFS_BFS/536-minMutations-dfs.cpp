#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>  //for std::find

using std::cout;
using STR=std::string;
using SET=std::set<STR>;
using VEC=std::vector<STR>;

bool dfoo(const STR& s,const STR& e, int d,const VEC& bank, SET& seen,int& ans)
{
    if(s==e)
    {
        ans=std::min(ans,d);
        return true;
    }
    if(seen.find(s)!=seen.end())
        return false;
    seen.insert(s);
    STR tmpChars{"ACGT"};
    int n=s.size();
    for(int i=0;i<n;++i)
    {
        for(auto &c:tmpChars)
        {
            STR nei=s.substr(0,i)+c+s.substr(i+1,n);
            if(nei!=s &&(std::find(std::begin(bank),std::end(bank),nei)!=std::end(bank)))
            {
                dfoo(nei,e,d+1,bank,seen,ans);
            }
        }
    }
    seen.erase(s);
}

int minMutations(const STR& s,const STR& e,const VEC& bank)
{
    int ans=INT_MAX;
    SET seen{};
    dfoo(s,e,0,bank,seen,ans);
    cout<<ans;
}

int main()
{
    STR s="AACCGGTT",e="AACCGGTA";
    VEC bank{"AACCGGTA"};
    minMutations(s,e,bank);
}

