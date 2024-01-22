
/**
 * You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:

1
2
3
4
5
6
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:

1
2
3
4
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:

1
2
3
4
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.
 * 
*/
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
      const string start{"0000"};

      if(start==target)
        return 0;
      unordered_set<string> dead(deadends.begin(),
                                 deadends.end()); // for more quick searching
      unordered_set<string> visited{start};
      queue<string> q{};
      q.push(start);
      int steps = 0;
      if (dead.count(target))
        return -1;
      while (!q.empty()) {

        ++steps;
        const int size = q.size();
        for (int k = 0; k < size; ++k) {
          const string cur = q.front();
          q.pop();
          for (int i = 0; i < 4; ++i) {
             //string nxt=cur;  //can not place here,will check the reason.
            for (int j = -1; j <= 1; j += 2) {
              string nxt = cur;
              nxt[i] = (nxt[i] - '0' + j + 10) % 10 + '0';
              if (nxt == target)
                return steps;
              if (dead.count(nxt) || visited.count(nxt))
                continue;
              q.push(nxt);
              visited.insert(nxt);
            }
          }
        }
      }
        return -1;
    }
};

int main() {
  vector<string> deadends{"0201", "0101", "0102", "1212", "2002"};
  string target = "0202";
  cout << Solution().openLock(deadends, target);
}