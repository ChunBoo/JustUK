/**
Given an array nums, there is a sliding window of size k which is moving from
the very left of the array to the very right. You can only see the k numbers in
the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

1
2
3
4
5
6
7
8
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
You may assume k is always valid, ie: 1 ≤ k ≤ input array’s size for non-empty
array.

Follow up:
Could you solve it in linear time?
*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution1 {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> ans;
    for (int i = k - 1; i < int(nums.size()); ++i)
      ans.push_back(
          *max_element(nums.begin() + i - k + 1, nums.begin() + i + 1));
    return ans;
  }
};

class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> window;
        for (int i = 0; i < int(nums.size()); ++i) {
          window.insert(nums[i]); // sorted the
          if (i - k + 1 >= 0) {
            ans.push_back(*window.rbegin());
            window.erase(window.equal_range(nums[i - k + 1]).first);
            // window.erase(nums[i-k+1]); //will delete all same elements which
            // is incorrect
          }
        }
        return ans;
    }
};

class MQueue{
    private:
        deque<int> q;
    public:
        void push(int e){
            while(!q.empty()&&e>q.back())  q.pop_back();
            q.push_back(e);
        }
        void pop(){
            q.pop_front();
        }
        int max() const {return q.front();}
};

class Solution3 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       MQueue q;
       vector<int> ans;
       for (int i = 0; i < int(nums.size()); ++i) {
         q.push(nums[i]);
         if (i - k + 1 >= 0) {
           ans.push_back(q.max());
           if (nums[i - k + 1] == q.max())
             q.pop();
         }
       }
       return ans;
    }
};

int main() {
  vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  vector<int> res1 = Solution1().maxSlidingWindow(nums, k);
  vector<int> res2 = Solution1().maxSlidingWindow(nums, k);
  vector<int> res3 = Solution1().maxSlidingWindow(nums, k);

  cout << "res1\n";
  for (int i : res1)
    cout << i << ',';
  cout << "res2\n";
  for (int i : res2)
    cout << i << ',';
  cout << "res3\n";
  for (int i : res3)
    cout << i << ',';
}