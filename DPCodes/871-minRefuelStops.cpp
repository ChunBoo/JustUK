
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        const int n=stations.size();
        vector<long> dp(n+1,startFuel); //store the max distance with j stops
        for(int i=0;i<n&&stations[i][0]<target;++i)
            for(int j=i+1;j>=1;--j)
                if(dp[j-1]>=stations[i][0])
                    dp[j]=max(dp[j],dp[j-1]+stations[i][1]);  //need to understand this line codes, why need to reverse
        for (int i = 0; i < int(dp.size()); ++i)
          if (dp[i] >= target)
            return i;
        return -1;
    }
};

int main() {
  int start = 10, target = 20;
  vector<vector<int>> stations{{8, 5}, {10, 8}};
  cout << Solution().minRefuelStops(target, start, stations);
}