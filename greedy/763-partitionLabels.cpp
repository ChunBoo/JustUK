class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(128,0);
        for(int i=0;i<s.size();++i)
            lastIndex[s[i]]=i;
        
        vector<int> ans{};

        int start=0,end=0;
        for(int i=0;i<s.size();++i)
        {
            end=max(end,lastIndex[s[i]]);
            if(end==i){
                ans.push_back(end-start+1);
                start=end+1;
            }
        }
        return ans;
    }
};