/**
 * Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.

 

Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]
 * 
*/

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        dfs(s,0,ans);
        return ans;
    }
    private:
        void dfs(string& S,int s,vector<string>& ans){
            if(s==S.length()){
                ans.push_back(S);
                return;
            }
            dfs(S,s+1,ans);
            if(!isalpha(S[s])) return;
            S[s]^=(1<<5);
            dfs(S,s+1,ans);
            S[s]^=(1<<5);
        }
};