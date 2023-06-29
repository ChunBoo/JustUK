
#include<iostream>
#include<string>
#include<vector>


using namespace std;
#if 1
class Solution {
public:
    int palindromePartition(string s, int k) {
        const int n=s.length();
        vector<vector<int>> cost(n,vector<int>(n));
        for(int l=2;l<=n;++l)
            for(int i=0,j=l-1;j<n;++i,++j)
                cost[i][j]=(s[i]!=s[j])+cost[i+1][j-1];
        
        vector<vector<int>> dp(n,vector<int>(k+1,INT_MAX/2));

        for(int i=0;i<n;++i){        //here the i means count of chars
            dp[i][1]=cost[0][i];
            for(int K=2;K<=k;++K)      // K means the count of groups
                for(int j=0;j<i;++j)  //  subProblem 
                    dp[i][K]=min(dp[i][K],dp[j][K-1]+cost[j+1][i]);
        }
        return dp[n-1][k];
    }
};
#endif
#if 0
class Solution {
public:
  int palindromePartition(string s, int K) {
    const int n = s.length();
    auto minChange = [&](int i, int j) {
      int c = 0;
      while (i < j) 
        if (s[i++] != s[j--]) ++c;      
      return c;
    };
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        cost[i][j] = minChange(i, j);
 
    // dp[i][j] := min changes to make s[0~i] into k palindromes
    vector<vector<int>> dp(n, vector<int>(K + 1, INT_MAX / 2));
    for (int i = 0; i < n; ++i) {      
      dp[i][1] = cost[0][i];
      for (int k = 1; k <= K; ++k)
        for (int j = 0; j < i; ++j)
          dp[i][k] = min(dp[i][k], dp[j][k - 1] + cost[j + 1][i]);        
    }
    return dp[n - 1][K];
  }
};
#endif
int main()
{
    string s{"abc"};
    cout<<Solution().palindromePartition(s, 2);
}