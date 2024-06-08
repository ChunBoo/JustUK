
/****
 * Given an array of integers called nums, you can perform any of the following operation while nums contains at least 2 elements:

Choose the first two elements of nums and delete them.
Choose the last two elements of nums and delete them.
Choose the first and the last elements of nums and delete them.
The score of the operation is the sum of the deleted elements.

Your task is to find the maximum number of operations that can be performed, such that all operations have the same score.

Return the maximum number of operations possible that satisfy the condition mentioned above.

 

Example 1:

Input: nums = [3,2,1,2,3,4]
Output: 3
Explanation: We perform the following operations:
- Delete the first two elements, with score 3 + 2 = 5, nums = [1,2,3,4].
- Delete the first and the last elements, with score 1 + 4 = 5, nums = [2,3].
- Delete the first and the last elements, with score 2 + 3 = 5, nums = [].
We are unable to perform any more operations as nums is empty.
Example 2:

Input: nums = [3,2,6,1,4]
Output: 2
Explanation: We perform the following operations:
- Delete the first two elements, with score 3 + 2 = 5, nums = [6,1,4].
- Delete the last two elements, with score 1 + 4 = 5, nums = [6].
It can be proven that we can perform at most 2 operations.
 

Constraints:

2 <= nums.length <= 2000
1 <= nums[i] <= 1000
 */

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        const int n=nums.size();
        
        vector<vector<int>> dp(n,vector<int>(n));
        bool isCompleted=false;
        auto fun=[&](int start,int end,int sum)->int{
            if(isCompleted)
                return 0;
            for(auto &row:dp){
                ranges::fill(row,-1);
            }

            function<int(int,int)> dfs=[&](int start,int end)->int{
                if(isCompleted)
                    return 0;
                if(start>=end){
                    isCompleted=true;
                    return 0;
                }
                int &ret=dp[start][end];
                if(ret!=-1)
                    return ret;
                ret=0;
                if(nums[start]+nums[start+1]==sum) ret=max(ret,dfs(start+2,end)+1);
                if(nums[start]+nums[end]==sum) ret=max(ret,dfs(start+1,end-1)+1);
                if(nums[end-1]+nums[end]==sum)  ret=max(ret,dfs(start,end-2)+1);
                return ret;
            };
            return dfs(start,end);
        };
        int ans1=fun(0,n-1,nums[0]+nums[1]);
        int ans2=fun(0,n-1,nums[0]+nums[n-1]);
        int ans3=fun(0,n-1,nums[n-2]+nums[n-1]);
        return max(ans1,max(ans2,ans3));
    }
};