//recursion for combination

#include<iostream>
#include<vector>
void getCurPermutation(std::vector<std::vector<int>>& ans,std::vector<int>& cur,int n,int k)
{
    if(cur.size()==k)
        ans.push_back(cur);

    for(int i=1;i<=n;++i)
    {
        cur.push_back(i);
        getCurPermutation(ans,cur,n,i);
        
    }
}

std::vector<std::vector<int>> getPermution(int n,int k)
{
    std::vector<std::vector<int>> ans;
    std::vector<int> cur;
    if(n<1||k<=0)
        return ans;
    getCurPermutation(ans,cur,n,k);
    return ans;
}


void getCurCombination(std::vector<std::vector<int>>& ans,std::vector<int>& cur,int curIdx,int k,int n)
{
    if(cur.size()==k)
    {
        ans.push_back(cur);
    }

    for(int i=curIdx;i<=n;++i)
    {
        cur.push_back(i);
        getCurCombination(ans,cur,i+1,k,n);
        cur.pop_back();
    }
}

std::vector<std::vector<int>> getCombination(int n,int k)
{
    // int sz=nums.size();
    
    std::vector<std::vector<int>> ans;
    if(n<1)
        return ans;
    std::vector<int> cur;
    getCurCombination(ans,cur,1,k,n);
    return ans;
}


int main()
{
    std::vector<std::vector<int>> res=getCombination(5,4);
    std::cout<<"Count: "<<res.size()<<'\n';
    for(auto i: res)
    {
        std::cout<<'\n';
        for(auto j:i)
            std::cout<<j<<' ';
    }
    return 0;
}