
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
      unsigned int mask = ~0;
      while (num & mask)
        mask <<= 1;
      return ~num ^ mask;
    }
};

class Solution2 {
public:
  int findComplement(int num) {
    vector<int> tmp;
    while (num) {
      tmp.push_back(num % 2);
      num /= 2;
    }
    std::reverse(tmp.begin(), tmp.end());
    long long ans = 0;
    for (auto i : tmp) {
      ans = (ans * 2) + (i ^ 1);
    }
    return ans;
  }
};

int main() {
  int num = 2;
  cout << Solution2().findComplement(num) << '\n';
  cout << Solution().findComplement(num) << '\n';
}