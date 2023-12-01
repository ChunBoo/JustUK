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



class Solution {  //HHJ
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        vector<vector<char>> d{10};
        d[0]={' '};
        d[1]={};
        d[2]={'a','b','c'};
        d[3]={'d','e','f'};
        d[4]={'g','h','i'};
        d[5]={'j','k','l'};
        d[6]={'m','n','o'};
        d[7]={'p','q','r','s'};
        d[8]={'t','u','v'};
        d[9]={'w','x','y','z'};
        string cur;
        vector<string> ans;
        dfs(digits,d,cur,ans,0);
        return ans;
    }
    void dfs(const string& digits,const vector<vector<char>>& d,string& cur,
             vector<string>& ans, int l)
    {
        if(l==digits.length())
        {
            ans.push_back(cur);
            return;
        }
        for(char c:d[digits[l]-'0'])
        {
            cur.push_back(c);
            dfs(digits,d,cur,ans,l+1);
            cur.pop_back();
        }
    }
};


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        vector<vector<char>> d{10};
        d[0]={' '};
        d[1]={};
        d[2]={'a','b','c'};
        d[3]={'d','e','f'};
        d[4]={'g','h','i'};
        d[5]={'j','k','l'};
        d[6]={'m','n','o'};
        d[7]={'p','q','r','s'};
        d[8]={'t','u','v'};
        d[9]={'w','x','y','z'};

        vector<string> ans{""};
        
        for(char digit:digits)
        {
            vector<string> tmp;
            for(const string& s:ans)
            {
                for(char c:d[digit-'0'])
                {
                    tmp.push_back(s+c);
                }
            }
            ans.swap(tmp);
        }
        return ans;
    
    }
};


int main()
{
    vector ret=Solution().letterCombinations("3");
    for(auto s:ret)
        cout<<s<<',';
}