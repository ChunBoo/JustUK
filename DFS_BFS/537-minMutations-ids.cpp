#include<set>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using std::cout;
using STR=std::string;
using VEC=std::vector<STR>;

bool DLS(const STR& s, const STR& e, int d,const VEC& bank, std::set<STR>& seen)
{
   if(s==e)
     return true;
   if(d<=0||seen.find(s)!=seen.end())   // here, the d should be less and equal to zero!!!
   {
    return false;
   }
   seen.insert(s);
   STR tmp{"ACGT"};
   int n=s.size();
   for(int i=0;i<n;++i)
   {
    for(auto &k:tmp)
    {
        STR nei=s.substr(0,i)+k+s.substr(i+1,n);
        if(nei!=s &&(std::find(bank.begin(),bank.end(),nei)!=std::end(bank))&&(DLS(nei,e,d-1,bank,seen)))
            return true;
    }
   }
   seen.erase(s);  //this line can not be skipped
   return false;   // and this line also can not be skipped.
}

int minMutations(const STR& s, const STR& e, const VEC& bank)
{
    std::set<STR> seen{};
    int sz=bank.size();
    int d=0;
    while(d<=sz)
    {
        if(DLS(s,e,d,bank,seen))
            return d;
        d+=1;
    }
    return -1;
}

int main()
{
    STR s="AACCGGTT",e="AACCGGTA";
    VEC bank{"AACCGGTA"};
    cout<<minMutations(s,e,bank);
}
