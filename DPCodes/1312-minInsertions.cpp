#include<iostream>
#include<string>
#include<cmath>

using STR=std::string;
using std::cout;

int dfs(const STR& s,int i,int j )
{
    if(i>=j)
        return 0;
    return s[i]==s[j]?dfs(s,i+1,j-1):std::min(dfs(s,i+1,j),dfs(s,i,j-1))+1;
    
}

int minInsertion(const STR& s)
{
    // int ans=INT_MAX;
    return dfs(s,0,s.size()-1);
}

int main()
{
    STR s = "mbabm";
    cout<<minInsertion(s);
}