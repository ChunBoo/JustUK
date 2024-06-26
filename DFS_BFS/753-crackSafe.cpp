/**
 * There is a safe protected by a password. The password is a sequence of n digits where each digit can be in the range [0, k - 1].

The safe has a peculiar way of checking the password. When you enter in a sequence, it checks the most recent n digits that were entered each time you type a digit.

For example, the correct password is "345" and you enter in "012345":
After typing 0, the most recent 3 digits is "0", which is incorrect.
After typing 1, the most recent 3 digits is "01", which is incorrect.
After typing 2, the most recent 3 digits is "012", which is incorrect.
After typing 3, the most recent 3 digits is "123", which is incorrect.
After typing 4, the most recent 3 digits is "234", which is incorrect.
After typing 5, the most recent 3 digits is "345", which is correct and the safe unlocks.
Return any string of minimum length that will unlock the safe at some point of entering it.

 

Example 1:

Input: n = 1, k = 2
Output: "10"
Explanation: The password is a single digit, so enter each digit. "01" would also unlock the safe.
Example 2:

Input: n = 2, k = 2
Output: "01100"
Explanation: For each possible password:
- "00" is typed in starting from the 4th digit.
- "01" is typed in starting from the 1st digit.
- "10" is typed in starting from the 3rd digit.
- "11" is typed in starting from the 2nd digit.
Thus "01100" will unlock the safe. "10011", and "11001" would also unlock the safe.
 * 
 * 
*/

#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>


using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
      const int totalSize = pow(k, n); // why is k^n
      string ans(n, '0');
      unordered_set<string> visited{ans};
      if (dfs(ans, totalSize, n, k, visited))
        return ans;
      return "";
    }
private:
  bool dfs(string &ans, const int totalSize, const int n, const int k,
           unordered_set<string> &visited) {
    if (totalSize == int(visited.size()))
      return true;
    string curNode = ans.substr(ans.length() - (n - 1), n - 1);
    for (char c = '0'; c < '0' + k; ++c) {
      curNode.push_back(c);   //push_back only work for one character
      if (!visited.count(curNode)) {
        ans.push_back(c);  //here is not ans.append(curNode)
        visited.insert(curNode);
        if (dfs(ans, totalSize, n, k, visited))
          return true;
        ans.pop_back();
        visited.erase(curNode);
      }
      curNode.pop_back();
    }
    return false;
  }
};

int main() { cout << Solution().crackSafe(2, 2); }