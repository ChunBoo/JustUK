/**
 * You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.
*/


/*
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> a;
        for(auto x:arr)
        {
            int mask=0;
            for(char c:x) mask|=1<<(c-'a');
            if(__builtin_popcount(mask)!=x.size())
                continue;
            a.push_back(mask);
        }
        int ans=0;
        function<void(int,int)> dfs=[&](int i,int mask)
        {
            ans=max(ans,__builtin_popcount(mask));
            for(int s=i;s<a.size();++s)
            {
                if((mask&a[s])==0)
                    dfs(i+1,mask|a[s]);
            }
        };
        dfs(0,0);
        return ans;
    }
};
*/
class Solution {
public:
  int maxLength(vector<string>& arr) {
    vector<int> a;
    
    for (const string& x : arr) {
      set<char> s(begin(x), end(x));
      if (s.size() != x.length()) continue;
      a.push_back(0);      
      for (char c : x) a.back() |= 1 << (c - 'a');      
    }
    
    int ans = 0;
    
    function<void(int, int)> dfs = [&](int s, int cur) {
      ans = max(ans, __builtin_popcount(cur));
      for (int i = s; i < a.size(); ++i)
        if ((cur & a[i]) == 0)
          dfs(i + 1, cur | a[i]);      
    };
    
    dfs(0, 0);
    return ans;
  }
};