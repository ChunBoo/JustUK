
/**
 * Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 * 
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class KMP{
    private:
        vector<int> build(string p)
        {
            int m=p.size();
            vector<int> nxt{0,0};
            int j=0;
            for(int i=1;i<m;++i)
            {
                while(j>0 && p[i]!=p[j])
                    j=nxt[j];
                if(p[i]==p[j])
                    j+=1;
                nxt.push_back(j);
            }
            return nxt;
        }
    public:
        vector<int> match(string s,string p)
        {
            int n=s.size(),m=p.size();
            vector<int> nxt=build(p);
            vector<int> ans;
            int j=0;
            for(int i=0;i<n;++i){
                while(j>0 && s[i]!=p[j])
                    j=nxt[j];
                if(s[i]==p[j])
                    j+=1;
                
                if(j==m){
                    ans.push_back(i-m+1);
                    j=nxt[j];
                }
            }
            return ans;
        }
};

class Solution {
private:
   
public:
    int strStr(string haystack, string needle) {
        vector<int> matched=KMP().match(haystack,needle);
        return matched.empty()?-1:matched[0];
    }
};

int main() {
  string haystack = "sadbutsad", needle = "sad";
  cout << Solution().strStr(haystack, needle);}
  //   vector<int> res = Solution().strStr(haystack, needle);
  //   for (auto &v : res)
  //     cout << v << ',';
  // }