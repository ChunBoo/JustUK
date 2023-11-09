/**
 * 
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        dfs(candidates,target,0,ans,curr);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
private:
    void dfs(const vector<int>& candidates,int target,int s,
             set<vector<int>>& ans,
              vector<int>& curr)
        {
            if(target==0)
            {
                ans.insert(curr);
                return;
            }
            for(int i=s;i<candidates.size();++i){
                int num=candidates[i];
                if(num>target) return;
                if(i>s&&candidates[i]==candidates[i-1]) continue;
                curr.push_back(num);
                dfs(candidates,target-num,i+1,ans,curr);
                curr.pop_back();
            }
        }
};


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        dfs(candidates,target,0,ans,curr);
        return ans;
    }
private:
    void dfs(const vector<int>& candidates,int target,int s,
             vector<vector<int>>& ans,
              vector<int>& curr)
        {
            if(target==0)
            {
                ans.push_back(curr);
                return;
            }
            for(int i=s;i<candidates.size();++i){
                int num=candidates[i];
                if(num>target) return;
                if(i>s&&candidates[i]==candidates[i-1]) continue;
                curr.push_back(num);
                dfs(candidates,target-num,i+1,ans,curr);
                curr.pop_back();
            }
        }
};