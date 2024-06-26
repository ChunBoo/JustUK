/*
There are n oranges in the kitchen and you decided to eat some of these oranges every day as follows:

Eat one orange.
If the number of remaining oranges n is divisible by 2 then you can eat n / 2 oranges.
If the number of remaining oranges n is divisible by 3 then you can eat 2 * (n / 3) oranges.
You can only choose one of the actions per day.

Given the integer n, return the minimum number of days to eat n oranges.

 

Example 1:

Input: n = 10
Output: 4
Explanation: You have 10 oranges.
Day 1: Eat 1 orange,  10 - 1 = 9.  
Day 2: Eat 6 oranges, 9 - 2*(9/3) = 9 - 6 = 3. (Since 9 is divisible by 3)
Day 3: Eat 2 oranges, 3 - 2*(3/3) = 3 - 2 = 1. 
Day 4: Eat the last orange  1 - 1  = 0.
You need at least 4 days to eat the 10 oranges.
Example 2:

Input: n = 6
Output: 3
Explanation: You have 6 oranges.
Day 1: Eat 3 oranges, 6 - 6/2 = 6 - 3 = 3. (Since 6 is divisible by 2).
Day 2: Eat 2 oranges, 3 - 2*(3/3) = 3 - 2 = 1. (Since 3 is divisible by 3)
Day 3: Eat the last orange  1 - 1  = 0.
You need at least 3 days to eat the 6 oranges.
 

Constraints:

1 <= n <= 2 * 109*/
#include <iostream>
#include <queue>
#include <unordered_set>


using namespace std;

class S {
public:
    int minDays(int n) {
      queue<int> q{{n}}; //{n} is wrong, as adaptor did not has the ctor for initializor list
      unordered_set<int> seen;
      int steps = 0;
      while (!q.empty()) {
        int size = q.size();
        while (size--) {
          int x = q.front();
          q.pop();
          if (x == 0)
            return steps;
          if (x % 2 == 0 && seen.insert(x / 2).second)
            q.push(x / 2);
          if (x % 3 == 0 && seen.insert(x / 3).second)
            q.push(x / 3);
          if (seen.insert(x - 1).second)
            q.push(x - 1);
        }
        ++steps;
        }
        return -1;
    }
};

int main() { cout << S().minDays(10); }