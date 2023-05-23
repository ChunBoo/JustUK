/*
Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8
*/
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz=tasks.size();
        vector<int> chars(26,0);
        for(char c:tasks)
            chars[c-'A']++;
        int maxFreq=*max_element(chars.begin(),chars.end());
        int ans=(maxFreq-1)*(n+1);
        int remains=count_if(chars.begin(),chars.end(),[&](int freq){return freq==maxFreq;});
        ans+=remains;
        return max(ans,sz);
    }
};

int main()
{
    vector<char> tasks{'A','A','A','B','B','B'};//,'C','C','C','C'};
    int n=2;
    cout<<Solution().leastInterval(tasks,n);
}