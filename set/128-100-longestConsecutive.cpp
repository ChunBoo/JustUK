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

int main()
{
// Input: nums = []
    VEC nums{5,4,200,1,3,2};
    cout<<longestConsecutive(nums);
}