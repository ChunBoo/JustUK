#include<algorithm>  //for std::set_difference
#include<set>
#include<iostream>
#include<vector>

using VEC=std::vector<int>;


std::vector<std::vector<int>> findDifferences(const VEC& nums1, const VEC& nums2)
{
    std::vector<std::vector<int>> ans{};

    std::set<int> res1,res2;
    std::set<int> s1{nums1.begin(),nums1.end()};
    std::set<int> s2{nums2.begin(),nums2.end()};

    std::set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),std::inserter(res1,res1.end()));
    std::set_difference(s2.begin(),s2.end(),s1.begin(),s1.end(),std::inserter(res2,res2.end()));
    return std::vector<std::vector<int>> {std::vector<int>{res1.begin(),res1.end()},std::vector<int>{res2.begin(),res2.end()}};
}

int main()
{
    VEC nums1{1,2,3};
    VEC nums2{2,4,6};

    std::vector<std::vector<int>>  res=findDifferences(nums1,nums2);
    for(auto &v:res)
    {
        std::cout<<'\n';
        for(auto &d:v)
            std::cout<<d<<',';
    }

}

