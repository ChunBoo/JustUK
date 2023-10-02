class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int m=target.size(),n=arr.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
        {
            int tmp=max(dp[i][j-1],dp[i-1][j-1]+(target[i-1]==arr[j-1]));
            dp[i][j]=max(dp[i-1][j],tmp);
        }
            
        return m-dp[m][n];
    }
};

class Solution {
private:
    int LIS(vector<int> l)
    {
        vector<int> dp;
        for(auto x:l)
            if(dp.empty() || x>dp.back())
                dp.push_back(x);
            else
                *lower_bound(begin(dp), end(dp), x) = x;
        return dp.size();
    }
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int m=target.size(),n=arr.size();
        map<int,int> _m;
        for(int i=0;i<m;++i)
            _m[target[i]]=i;
        vector<int> l;
        for(auto x:arr)
        {
            auto mit = _m.find(x);
            if (mit == end(_m)) continue;
            l.push_back(_m[x]);
        }
        return m-LIS( l);
    }
};