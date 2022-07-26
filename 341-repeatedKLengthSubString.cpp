/*
341-repeatedKLengthSubString
given a string, return the count of the substrings which occurred more than once
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
    string cur{};

    for(auto &c:s)
    {
        cur+=c;
        if(cur.size()>k)
        {
            cur=cur.substr(1);  //substr will create a new copy of string 
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
