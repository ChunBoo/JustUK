#include<map>
#include<iostream>
#include<string>

using DT=std::map<char,int>;

DT myCounter(const std::string& str)
{
    DT ans{};
    for(auto &c:str)
    {
        ans[c]+=1;
    }
    return ans;
}


int subStrings(const std::string& s0,const std::string& s1)
{
    int n0=s0.size(),n1=s1.size();
    int R=n0;
    int ans=0;

    DT Cur=myCounter(s1.substr(0,R));
    DT C=myCounter(s0);

    if(C==Cur)
        ans+=1;
    while(R<n1)
    {
        Cur[s1[R]]+=1;
        Cur[s1[R-n0]]-=1;
        if(Cur[s1[R-n0]]==0)
        {
            Cur.erase(s1[R-n0]);
        }
        if(Cur==C)
            ans+=1;
        R+=1;
    }
    return ans;
}

int main()
{
    std::string s0{"abc"},s1{"baccdacb"};
    std::cout<<subStrings(s0,s1);
}

    
        

