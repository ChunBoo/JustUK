#include<map>
#include<iostream>
#include<string>

using DT=std::map<char,int>;

DT myCounter(const std::string& str)
{
    DT ans{};
    if(str.empty())
        return ans;
    for(auto c:str)
        ans[c]+=1;
    return ans;
}


int subStrings(const std::string& s0,const std::string& s1)
{
    int n0=s0.size(),n1=s1.size();
    int R=n0,ans=0;

    DT C=myCounter(s0);
    DT cur=myCounter(s1.substr(0,R));
    if(C==cur)
        ans+=1;
    while(R<n1)
    {
        cur[s1[R]]+=1;
        cur[s1[R-n0]]-=1;
        if(cur[s1[R-n0]]==0)
        {   
            // std::map<char,int>::iterator it=cur.begin();
            cur.erase(s1[R-n0]);
        }
        if(cur==C)
            ans+=1;
        R+=1;
    }
    return ans;
}

int main()
{
    std::string s0{"abc"},s1{"bacbdacb"};
    std::cout<<subStrings(s0,s1);
}

    
        

