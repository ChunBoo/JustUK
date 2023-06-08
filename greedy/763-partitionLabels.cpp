#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

using VEC=std::vector<int>;

class Solution {
public:
    VEC partitionLabels(const string& s) {
        int n=s.size();
        VEC ans{};
        VEC lastIndex(128,0);
        for(int i=0;i<n;++i)
        {
            lastIndex[s[i]]=i;
        }

        int start=0,end=0;
        for(int i=0;i<n;++i)
        {
            end=max(end,lastIndex[s[i]]);
            if(end==i)
            {
                ans.push_back(end-start+1);
                start=end+1;  //here should update the start as end+1
            }
        }
        return ans;
    }
};

int main()
{
    string s{"ababcbacadefegdehijhklij"};
    vector<int> res=Solution().partitionLabels(s);
    for(auto v:res)
        cout<<v<<',';
}