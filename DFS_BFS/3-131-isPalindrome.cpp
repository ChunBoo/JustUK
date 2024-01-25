/**
 * Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>> ans;
        vector<string> cur;
        function<void(int)> dfs=[&](int start)
        {
            if(start==n)
            {
                ans.push_back(cur);
                return;
            }
            for(int i=start;i<n;++i)
            {
                if(!isPalindrome(s,start,i))
                    continue;
                cur.push_back(s.substr(start,i-start+1));
                dfs(i+1);
                cur.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
private:
    bool isPalindrome(const string& s,int l,int r)
    {
        while(l<r)
            if(s[l++]!=s[r--])
                return false;
        return true;
    }
};