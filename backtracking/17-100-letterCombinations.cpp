#include<iostream>
#include<string>
#include<vector>

using std::cout;
using string=std::string;
using vector=std::vector<string>;

class Solution {
public:

    void dfs(int begin,string cur,int totalLen,vector& mm,vector& ans,string& digits)
    {
        if(begin==totalLen)
        {
            ans.push_back(cur);
            return;
        }
        int digit=digits[begin]-'0';
        string curLetters=mm[digit];
        for(auto c:curLetters)
            dfs(begin+1,cur+c,totalLen,mm,ans,digits);
    }
    vector letterCombinations(string digits) {
        int n=digits.size();
        vector ans{};
        vector mm{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        if(n==0)
            return ans;
        dfs(0,"",n,mm,ans,digits);
        return ans;
    }
};
int main()
{
    vector ret=Solution().letterCombinations("3");
    for(auto s:ret)
        cout<<s<<',';
}