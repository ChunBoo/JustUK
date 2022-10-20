#include<iostream>
#include<vector>
#include<algorithm>

using VEC=std::vector<int>;

VEC sortOddEven(VEC& nums)
{
    VEC odd{};
    VEC even{};

    for(int i=0;i<nums.size();++i)
    {
        if(i&1)
            odd.push_back(nums[i]);
        else
            even.push_back(nums[i]);
    }

    std::sort(odd.begin(),odd.end(),std::greater<int>());
    std::sort(even.begin(),even.end());

    VEC ans{};
    int i=0,j=0;
    while(i<odd.size() && j<even.size())
    {
        ans.push_back(even[j]);
        ans.push_back(odd[i]);
        ++i,++j;
    }
    // while(i<odd.size())   //this step is unnecessary,as the even index always larger than odd index
    //     ans.push_back(odd[i++]);
    while(j<even.size())
        ans.push_back(even[j++]);
    return ans;

}

int main()
{
    VEC nums{4,1,2,3};
    VEC res=sortOddEven(nums);
    for(auto v:res)
        std::cout<<v<<',';

}
