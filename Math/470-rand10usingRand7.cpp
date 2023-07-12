// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
#include <cmath>
#include <iostream>


using namespace std;

class Solution {
public:
    int rand10() {
        int index=INT_MAX;
        while(index>=40)  //resampling
            index=7*(rand7()-1)+(rand7()-1);
        return index%10+1;
    }

  private:
    unsigned int rand7() { return rand() % 7; }
};

int main() {
  for (int i = 1; i < 20; ++i)
    cout << Solution().rand10() << '\n';
}