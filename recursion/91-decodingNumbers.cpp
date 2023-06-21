/**
 * A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
Given a string s containing only digits, return the number of ways to decode it.
The test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
 * 
*/
#include<unordered_map>
#include<string>
#include<iostream>

using std::cout;
using namespace std;

class Solution {
private:
    unordered_map<int,int> m_ways{};   //key is the index, value is the count of ways
    int ways(const string& s,int l,int r)  //l is the previous position, r is the next position
    {
        if(m_ways.count(l)) return m_ways[l];
        if(l>=r) return 1;//empty string,check here why empty string also is reasonable
        if(s[l]=='0') return 0;
        int w=ways(s,l+1,r);
        int prefix=(s[l]-'0')*10+s[l+1]-'0';
        if(prefix<=26)
            w+=ways(s,l+2,r);
        m_ways[l]=w;
        return w;
    }
public:

    int numDecodings(string s) {
        return ways(s,0,s.size()-1);
    }
};

class Solution {
private:
    unordered_map<string,int> m_ways{};
    int ways(const  string& s)
    {
        if(m_ways.count(s)) 
            return m_ways[s];
        if(s[0]=='0')
            return 0;
        if(s.length()==1)
            return 1;
        int w=ways(s.substr(1));
        int prefix=(s[0]-'0')*10+s[1]-'0';
        if(prefix<=26)
            w+=ways(s.substr(2));
        m_ways[s]=w;
        return w;

        // if(m_ways.count(l)) return m_ways[l];
        // if(s[l]=='0') return 0;
        // if(l>=r) return 1;
        // int w=ways(s,l+1,r);
        // const int prefix=(s[l]-'0')*10+(s[l+1]-'0');
        // if(prefix<=26)
        //     w+=ways(s,l+2,r);
        // m_ways[l]=w;
        // return w;
    }
public:

    int numDecodings(string s) {
        // return ways(s,0,s.size()-1);
        m_ways[""]=1;
        return ways(s);
    }
};


int main()
{
    std::string s{"12"};
    cout<<Solution().numDecodings(s);
}