#include <algorithm> //for min_element
#include <cmath>
// #include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution1 {
public:
  int minimumDistance(string word) {
    constexpr int K = 26;
    const int n = word.length();
    vector<vector<vector<int>>> mem(n,
                                    vector<vector<int>>(27, vector<int>(27)));
    auto cost = [](int c1, int c2) {
      if (c1 == K)
        return 0;
      return abs(c1 / 6 - c2 / 6) +
             abs(c1 % 6 - c2 % 6); // FORMAT:      "A   B   C   D   E   F" ，
                                   // each line has 6 characters, so c1/6 will
                                   // get the rows#, c1%6 get the col#
    };
    // min cost to type word[i:n], l,r are the last finger position
     function<int(int, int, int)> dp = [&](int i, int l, int r) {
    //auto dp = [](int i, int l, int r) {  // use the lambda function here can not work, as the recursion here?
      if (i == n)
        return 0;
      if (mem[i][l][r])
        return mem[i][l][r];
      int c = word[i] - 'A';
      return mem[i][l][r] = min(dp(i + 1, c, r) + cost(l, c),
                                dp(i + 1, l, c) + cost(r, c));
    };
      return dp(0, K, K);
  }
};

class Solution2 {
public:
  int minimumDistance(string word) {
    constexpr int K = 26;
    const int n = word.length();
    vector<vector<int>> mem(n, vector<int>(27));
    auto cost = [](int c1, int c2) {
      if (c1 == K)
        return 0;
      return abs(c1 / 6 - c2 / 6) + abs(c1 % 6 - c2 % 6);
    };
    // min cost to type word[i:n], l,r are the last finger position
    function<int(int, int)> dp = [&](int i, int o) {
      if (i == n)
        return 0;
      if (mem[i][o])
        return mem[i][o];
      int p = i == 0 ? K : word[i - 1] - 'A';
      int c = word[i] - 'A';
      return mem[i][o] =
                 min(dp(i + 1, o) + cost(p, c), dp(i + 1, p) + cost(o, c));
    };
    return dp(0, K);
  }
};

class Solution3 {
public:
  int minimumDistance(string word) {
    constexpr int kRest = 26;
    const int n = word.length();
       
    // dp[i][j] : min cost to type word[0:i]
    // one finger is at word[i - 1], another finger is at j.
    vector<vector<int>> dp(n + 1, vector<int>(27, INT_MAX / 2));
    
    dp[0][kRest] = 0;
    
    auto cost = [](int c1, int c2) {
      if (c1 == kRest) return 0;
      return abs(c1 / 6 - c2 / 6) + abs(c1 % 6 - c2 % 6);
    };
    
    for (int i = 0; i < n; ++i) {
      int p = i == 0 ? kRest : word[i - 1] - 'A';
      int c = word[i] - 'A';
      for (int j = 0; j <= 26; ++j) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + cost(p, c));  // same finger
        dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + cost(j, c)); // other finger
      }
    }
    
    return *min_element(begin(dp[n]), end(dp[n]));
  }
};

int main() {
  string word{"CAKE"};
  cout << Solution1().minimumDistance(word) << '\n';
  cout << Solution1().minimumDistance(word) << '\n';
  cout << Solution1().minimumDistance(word) << '\n';
}