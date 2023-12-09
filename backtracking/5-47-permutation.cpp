/**
 * Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/


#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;

class Solution2 {
private:
    void dfs(const vector<int>& nums,vector<int>& cur, vector<bool>& used,
    vector<vector<int>>& ans)
    {
        if(cur.size()==nums.size())
        {
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<int(nums.size());++i)
        {
            if(used[i])
                continue;
            if(i>0&&nums[i]==nums[i-1]&&!used[i-1])
                continue;
            used[i]=1;
            cur.push_back(nums[i]);
            dfs(nums,cur,used,ans);
            cur.pop_back();
            used[i]=0;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> used(n,false);
       

        dfs(nums,cur,used,ans);
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        vector<vector<int>> ans;
          vector<int> cur;
        vector<bool> used(n,false);
        function<void()> dfs=[&]()
        {
            if(int(cur.size())==n)
            {
                ans.push_back(cur);
                return;
            }
            for(int i=0;i<n;++i)
            {
                if(used[i])
                  continue;
                if(i>0&&nums[i]==nums[i-1]&&!used[i-1]) 
                    continue;
                used[i]=true;
                cur.push_back(nums[i]);
                dfs();
                cur.pop_back();
                used[i]=false;
            }
            
        };

        dfs();
        return ans;
    }
};

int main()
{
    vector<int> nums = {1,1,2};
    vector<vector<int>> ans=Solution().permuteUnique(nums);
    for(auto v:ans)
    {
        cout<<'\n';
        for(auto d:v)
            cout<<d<<',';
    }
}