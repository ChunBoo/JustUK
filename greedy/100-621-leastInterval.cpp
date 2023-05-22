/*
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz=tasks.size();
        vector<int> chars(26,0);
        for(char c:tasks)
            chars[c-'A']++;
        
        int maxFreq=*max_element(chars.begin(),chars.end());
        int ans=(maxFreq-1)*(n+1);
        ans+=count_if(chars.begin(),chars.end(),[&](int frq){return frq==maxFreq;});
        return max(ans,sz);
    }
};