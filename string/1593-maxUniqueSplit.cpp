
/**
 * Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
Example 2:

Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba'].
Example 3:

Input: s = "aa"
Output: 1
Explanation: It is impossible to split the string any further.
 

Constraints:

1 <= s.length <= 16

s contains only lower case English letters.
*/

#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string_view s) {
        const int n=s.length();
        size_t ans=0;
        unordered_set<string_view> seen;
        for(int m=0;m<1<<(n-1);++m){   //what's usage of m here, will control which condition
            if(__builtin_popcount(m)<ans) continue;
            bool valid=true;
            int p=0;
            for(int i=0;i<n&&valid;++i){
                if(m&(1<<i)||i==n-1){
                    valid&=seen.insert(s.substr(p,i-p+1)).second;
                p=i+1;
                }
            }
            if(valid) ans=max(ans,seen.size());
            seen.clear();
        }
        return ans;
    }
};

class Solution2 {
public:
    int maxUniqueSplit(string s) {
        size_t ans=1;
        const int n=s.length();
        unordered_set<string_view> seen;
        function<void(int)> dfs=[&](int p){
            if(p==n){
                ans=max(ans,seen.size());
                return;
            }
            for(int i=p;i<n;++i){
                string ss=s.substr(p,i-p+1); //can not use string_view here
                if(!seen.insert(ss).second) continue;
                dfs(i+1);
                seen.erase(ss);
            }
        };
        dfs(0);
        return ans;
    }
};

int main() {
  string s = "ababccc";
  cout << Solution().maxUniqueSplit(s);
}