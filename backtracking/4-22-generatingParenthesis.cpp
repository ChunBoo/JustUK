/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        // string s;
        if(n<0) return ans;
        dfs(n,n,cur,ans);
        return ans;
    }
    void dfs(int l,int r, string&cur, vector<string>& ans )
    {
        if(l+r==0)
          ans.push_back(cur);
        if(r<l)
            return;
        if(l>0)
        {
            dfs(l-1,r,cur+='(',ans);
            cur.pop_back();
        }
        if(r>0)
        {
            dfs(l,r-1,cur+=')',ans);
            cur.pop_back();
        }
    }
};