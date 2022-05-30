//given a list of numbers,return the count of pairs with K differences
//likes: [1,2,2,1], return 4,when k=1,that is:{1,2},{1,2},{2,1},{2,1}

#include<vector>
#include<map>
#include<iostream>


using MAP=std::map<int,int>;
using LIST=std::vector<int>;


MAP myCounter(const LIST& nums)
{
    MAP ans{};
    for(auto &i:nums)
        ans[i]+=1;
    return ans;
}


int countOfPairsWithMap(const LIST& nums,int k)
{
    // MAP c=myCounter(nums);
    std::map<int,int> c{};
    int ans{0};
    for(auto &v:nums)
    {
        ans+=c[v-k];
        ans+=c[v+k];
        // ans+=c[i+k]; 
        c[v]+=1;
    }
    return ans;
}

int main()
{
    LIST nums{1,2,2,1};
    std::cout<<countOfPairs(nums,1);
    return 0;
}