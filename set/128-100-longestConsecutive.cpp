/*
Given an unsorted array of integers nums, 
return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
Therefore its length is 4.
*/
#include<iostream>
#include<set>
#include<vector>
#include<cmath>
using std::cout;
using SET=std::set<int>;
using VEC=std::vector<int>;

int longestConsecutive(const VEC& nums)
{
    int ans=0;
    SET s{nums.begin(),nums.end()};
    int step=1;
    for(auto i:s)
    {
        if(s.find(i-1)!=s.end())
            continue;
        while(s.find(i+1)!=s.end())
        {
            step+=1;
            i+=1;
        }
        ans=std::max(step,ans);
        step=1;
    }
    return ans;
}
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set<int> h{nums.begin(),nums.end()};

        // int ans=0;
        // for(auto i:nums)
        // {
        //     if(!h.count(i-1)){
        //         int l=0;
        //         while(h.count(i++)) l+=1;
        //         ans=max(ans,l);
        //     }
        // }
        // return ans;
        unordered_map<int,int> m{};
        int ans=0;

        for(auto i:nums)
        {
            if(m.count(i))
                continue;
            auto it_l=m.find(i-1);
            auto it_r=m.find(i+1);
            int l=it_l!=m.end()?it_l->second:0;
            int r=it_r!=m.end()?it_r->second:0;
            int t=l+r+1;
            m[i]=m[i-l]=m[i+r]=t;
            ans=max(ans,t);
            // if(l>0&&r>0)
            // {
            //     m[i-l]=m[i]=m[i+r]=r+l+1;
            // }
            // else if(l>0)
            //     m[i-l]=m[i]=l+1;
            // else if(r>0)
            // m[i+r]=m[i]=r+1;
            // else
            //     m[i]=1;
        }
        // for(auto const &kv:m)
        //     ans=max(ans,kv.second);
        return ans;
    }
};
int main()
{
// Input: nums = []
    VEC nums{5,4,200,1,3,2};
    cout<<longestConsecutive(nums);
}