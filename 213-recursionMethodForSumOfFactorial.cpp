#include<deque>
#include<iostream>

bool dfs(int idx,int v,std::deque<int>& q)
{
    if(v==0)
        return true;
    if(v<0)
        return false;
    if(idx>=q.size())
        return false;
    
    return dfs(idx+1,v-q[idx],q) || dfs(idx+1,v,q);
}

bool isSumOfFactorial(int n)
{
    if(n<1)
        return false;
    
    std::deque<int> q{};
    int fact=1,x=1;
    while(fact<=n)
    {
        fact*=x;
        q.push_front(fact);
        ++x;
    }
    return dfs(0,n,q);
}


int main()
{
    std::cout<<isSumOfFactorial(4);
    return 0;
}