//recursion for combination

#include<iostream>
#include<vector>
#include<algorithm>
void getCurPermutation(std::vector<std::vector<int>>& ans,std::vector<int>& cur,int k)
{
    if(std::find(ans.begin(),ans.end(),cur)==ans.end())
    {
        ans.push_back(cur);
        return ;
    }
    for(int i=0;i<cur.size()-1;++i)
    {
        std::swap(cur[i],cur[i+1]);
        getCurPermutation(ans,cur,k);
        std::swap(cur[i],cur[i+1]);
    }
}

std::vector<std::vector<int>> getPermution(std::vector<int>& nums,int k)
{
    std::vector<std::vector<int>> ans;
    if(k<=0)
        return ans;
    getCurPermutation(ans,nums,k);
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
    #if 0
    std::vector<std::vector<int>> res=getCombination(5,4);
    std::cout<<"Count: "<<res.size()<<'\n';
    for(auto i: res)
    {
        std::cout<<'\n';
        for(auto j:i)
            std::cout<<j<<' ';
    }
    #endif
    std::vector<int> ivector{1,2,3,4,5};
    std::vector<std::vector<int>> ans=getPermution(ivector,5);
    for(auto i:ans)
    {
        std::cout<<'\n';
        for(auto j:i)
            std::cout<<j<<' ';
    }
    /* std::swap()
    std::swap(ivector[0],ivector[1]);
    for(auto i:ivector)
        std::cout<<i<<' ';
    */
    return 0;
}