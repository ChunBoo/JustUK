#include<random>
#include<iostream>
#include<vector>

using std::cout;
using VEC=std::vector<int>;


VEC QuickSorting( VEC& nums)
{
    int n=nums.size();
    if(n<=1)
        return nums;
    int randIndex=rand()%n;
    int pivot=nums[randIndex];
    VEC smaller{};
    VEC equal{};
    VEC greater{};

    for(auto &i:nums)
    {
        if(i<pivot)
            smaller.push_back(i);
        if(i==pivot)
            equal.push_back(i);
        if(i>pivot)
            greater.push_back(i);
    }
    //extend
    QuickSorting(smaller);
    QuickSorting(greater);
    smaller.reserve(smaller.size()+distance(equal.begin(),equal.end()));
    smaller.insert(smaller.end(),equal.begin(),equal.end());
    smaller.reserve(smaller.size()+distance(greater.begin(),greater.end()));
    smaller.insert(smaller.end(),greater.begin(),greater.end());
    return smaller;
}

int main()
{
    VEC nums{5,2,1,4,3,4};
    VEC res=QuickSorting(nums);
    for(auto &v:res)
        cout<<v<<',';
}