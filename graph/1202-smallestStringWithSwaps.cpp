/**
 * You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

 

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 

Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.
*/

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<vector<int>> g(s.length());
        unordered_set<int> seen;
        vector<int> idx;
        string tmp;

        for(const auto&e:pairs){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        function<void(int)> dfs=[&](int cur){
            if(seen.count(cur)) return;
            seen.insert(cur);
            idx.push_back(cur);
            tmp+=s[cur];
            for(int nxt:g[cur]) dfs(nxt);
        };

        for(int i=0;i<s.length();++i){
            if(seen.count(i)) continue;
            idx.clear();
            tmp.clear();
            dfs(i);
            sort(begin(tmp),end(tmp));
            sort(begin(idx),end(idx));
            for(int k=0;k<idx.size();++k)
                s[idx[k]]=tmp[k];
        }
        return s;
    }
};