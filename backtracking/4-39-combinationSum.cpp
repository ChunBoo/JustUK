/**
 * @brief 
 * Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
 * 
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        const int n=candidates.size();
        vector<int> cur;
        vector<vector<int>> ans;

        std::sort(begin(candidates),end(candidates));
        dfs(candidates,0,target,cur,ans);
        return ans;
    }
private:
    void dfs(vector<int>& nums,int s,int target,vector<int>& cur,vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(cur);
            return ;
        }
        for(int i=s;i<nums.size();++i)
        {
            if(nums[i]>target)
                break;
            cur.push_back(nums[i]);
            dfs(nums,i,target-nums[i],cur,ans);
            cur.pop_back();
        }
    }
};