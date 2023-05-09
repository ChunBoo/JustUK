//given a integer, return the total count of binary search trees which can be created by values in range [1,n];
#include<iostream>
#include<vector>

using VEC=std::vector<int>;
using std::cout;

class Solution {
public:
    int numTrees(int n) {
        VEC dp(n+1,0);
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;++i)
        {
            for(int j=1;j<=i;++j)
                dp[i]+=dp[i-j]*dp[j-1];
        }
        return dp[n];
        
    }
};

int main()
{
    int res=Solution().numTrees(3);
    cout<<res;
}