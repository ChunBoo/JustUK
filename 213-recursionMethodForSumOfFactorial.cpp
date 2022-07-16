//likes dp method
#include<deque>
#include<iostream>

bool dfs(int idx,int v,std::deque<int>& q)
{
    if(v==0)
        return true;
    if(idx>q.size())
        return false;
    if(v<0)
        return false;
    return dfs(idx+1,v-q[idx],q) || dfs(idx+1,v,q);
}

bool isSumOfFactorial(int n)
{
    if(n<1)
        return false;

    std::deque<int> q;
    int x=1,fact=1;
    while(fact<=n)
    {
        fact*=x;
        q.push_back(fact);
        ++x;
    }
    return dfs(0,n,q);
}


int main()
{
    std::cout<<isSumOfFactorial(24);
    return 0;
}