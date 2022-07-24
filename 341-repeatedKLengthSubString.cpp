/*
341-repeatedKLengthSubString

*/

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int repeatedKLenSubString(const string& s,int k)
{
    unordered_map<string,int> data;

    string cur{};

    for(int i=0;i<s.size();++i)
    {
        cur+=s[i];
        if(cur.size()>k)
            cur=cur.substr(1);
        data[cur]++;
        
    }

    int ans=0;
    for(auto &[a,b] : data)
    {
        if(b>1)
            ans++;
    }
    return ans;
}

int main()
{
    string s{"abcdabc"};
    int res=repeatedKLenSubString(s,3);
    std::cout<<res<<'\n';
    return 0;
}
