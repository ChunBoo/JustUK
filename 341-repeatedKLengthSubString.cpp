/*
341-repeatedKLengthSubString
given a string, return the count of the substrings which occurred more than once

Given a string s and an integer k, 
return the number of k-length substrings that occur more than once in s.
Constraints
n ≤ 100,000 where n is the length of s.
k ≤ 10
Example 1
Input
s = “abcdabc”
k = 3
Output
1
Explanation
“abc” occurs twice in the string

Example 2
Input
s = “aaabbb”
k = 2
Output
2
Explanation
Both “aa” and “bb” occurs twice.

Hints:
Use Hash Table to keep track of k-length substrings
s=”aaaa” and k = 3 expects 1.
Sliding window and frequency?
*/
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int repeatedKLenSubString(const string& s,int k)
{
    int ans=0;
    if(s.empty())
        return ans;
    unordered_map<string,int> data{};
    string cur="";
    for(auto &c:s)
    {
        cur+=c;
        if(cur.size()>k)
        {
            cur=cur.substr(1);
        }
        data[cur]+=1;
    }
    for(auto &[a,b] :data)
    {
        if(b>1)
            ans++;
    }
    return ans;
}

int main()
{
    string s{"aaabbb"};
    // string s{"abcdabc"};
    int res=repeatedKLenSubString(s,2);
    std::cout<<res<<'\n';
    return 0;
}
