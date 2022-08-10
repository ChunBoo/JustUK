//greedy algorithm
#include<vector>
#include<iostream>
#include<algorithm>

using VEC=std::vector<int>;

VEC largestSumOfKLengthSubsequence(const VEC& nums,int k)
{
    VEC ans{};
    
    int sz=nums.size();
    if(k<0||k>sz)
        return ans;

    ans=VEC(nums.begin(),nums.begin()+k);  //constructor, will be copy the begin to begin+k-1
    for(int i=k;i<sz;++i)
    {
        std::vector<int>::iterator minVal=std::min_element(ans.begin(),ans.end());
        if(nums[i]>*minVal)
        {
            ans.erase(minVal);              //erase(iterator), python is remove(element)
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

int main()
{
    VEC nums{3,5,2,1,7,7};
    VEC res=largestSumOfKLengthSubsequence(nums,3);
    for(auto &i:res)
        std::cout<<i<<',';
    return 0;
}