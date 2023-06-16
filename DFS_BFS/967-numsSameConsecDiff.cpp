/**
 * Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.

Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
 * 
*/

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        if(n==1)
            ans.push_back(0);
        for(int i=1;i<=9;++i)
            dfs(n-1,k,i,ans);
        return ans;
    }
private:
    void dfs(int n,int k,int cur,vector<int>& ans){
        if(n==0){
            ans.push_back(cur);
            return;
        }
        int l=cur%10;
        if(l+k<=9)
        {
            dfs(n-1,k,cur*10+l+k,ans);
        }
        if(l-k>=0 &&k!=0)
            dfs(n-1,k,cur*10+l-k,ans);
    }
};