class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans{0};
        for(int i=1;i<=n;++i)
        {
            if(i&1)
                ans.push_back(ans[i-1]+1);
            else
                ans.push_back(ans[i/2]);
        }
        return ans;
    }
};

class Solution {
public:
    int cnt(int n)
    {
        int ans=0;
        while(n)
        {
            ans+=1;
            n&=(n-1);
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans{0};
        for(int i=1;i<=n;++i)
        {
            ans.push_back(cnt(i));
        }
        return ans;
    }
};