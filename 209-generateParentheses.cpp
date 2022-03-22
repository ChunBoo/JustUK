#include<string>
#include<iostream>
#include<vector>
using DT=std::string;
using DT2=std::vector<std::string>;
void dfs(DT2& vec,DT s,int open,int close,int n)
{
    if(s.size()==n*2)
    {
        if(open==close)
        {
            vec.push_back(s);

            return;
        }
    }
        // dfs(vec,s,open+1,close,n);

    if(open<n)
    {
        // s+='(';
        dfs(vec,s+'(',open+1,close,n);
    }
    if(open>close)
    {
        // s+=')';
        dfs(vec,s+')',open,close+1,n);
    }
    
}

DT2 getValidParentheses(int n)
{
    DT2 ans{};
    DT s{};
    dfs(ans,"",0,0,n);
    return ans;
}

int main()
{
    DT2 res=getValidParentheses(2);
    for(auto v:res)
    {
        std::cout<<v<<'\n';
    }
    return 0;
}