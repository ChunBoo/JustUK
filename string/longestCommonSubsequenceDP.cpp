#include <cmath>
#include <iostream>
#include <string>

#include <deque>
#include<algorithm>
using namespace std;
class CTest{
public:
string getLCS()
{
    return {begin(res),end(res)};
}
int lcs(string s1, string s2, int m, int n) {
  if (m == 0 || n == 0)
    return 0;
  if (s1[m - 1] == s2[n - 1])
  {
    if(std::find(res.begin(),res.end(),s1[m-1])==res.end())
        res.push_front(s1[m-1]);
    return 1 + lcs(s1, s2, m - 1, n - 1);
  }
  return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
  }
private:
    deque<char> res;
};

int main() {
  string s1 = "ABCDGH", s2 = "AEDFHR";
  CTest test;
  cout << test.lcs(s1, s2, s1.size(), s2.size());
  cout<<test.getLCS();
}