//dp 

#include<iostream>
#include<vector>
#include<map>
int dfBottom2Up(const std::vector<int>& vals)
{
    if(vals.empty())
        return 0;
    int sz=vals.size();
    if(sz==1)
        return vals[0];
    if(sz==2)
        return std::max(vals[0],vals[1]);
    std::map<int,int> dp{};
    dp[0]=vals[0];
    dp[1]=std::max(dp[0],vals[1]);

    for(int i=2;i<sz;++i)
    {
        dp[i]=std::max(vals[i]+dp[i-2],dp[i-1]);
    }
    return dp[sz-1];
}

int dfTop2Down(const std::vector<int>& val,int n,std::map<int,int>& nb)
{
    
    int sz=val.size();
    if(n<0||n>sz)
        return 0;
    if(sz==0)
        return 0;
    if(sz==1)
        return val[0];
    
    std::map<int,int>::iterator it=nb.find(n);
    if(it!=nb.end())
        return nb[n];
    
    int temp=std::max(val[n]+dfTop2Down(val,n-2,nb),dfTop2Down(val,n-1,nb));
    nb[n]=temp;
    return nb[n];
}


int main()
{
    std::vector<int> val{1,9,10};
    std::map<int,int> nb{};
    int result=dfTop2Down(val,3,nb);
    // int result=getMax(val,3);
    std::cout<<"Result is: "<<result<<'\n';

    return 0;
}