#include<string>
#include<iostream>
#include<vector>
using DT=std::string;
using DT2=std::vector<std::string>;
void dfs(DT2& vec,DT s,int open,int close,int n) //here the s can not be reference,
{
        if(s.size()==2*n)
        {
            if(open==close)
            {
                vec.push_back(s);
                return;
            }
        }
    
    if(open<n)
        dfs(vec,s+'(',open+1,close,n);
    if(close<open)
        dfs(vec,s+')',open,close+1,n);
    
}

DT2 getValidParentheses(int n)
{
    DT2 ans{};
    if(n<1)
        return ans;
    std::string s{};
    dfs(ans,s,0,0,n);
    return ans;
}

int main()
{
    DT2 res=getValidParentheses(3);
    for(auto v:res)
    {
        std::cout<<v<<'\n';
    }
    return 0;
}