
/**
 * Given an integer array nums, handle multiple queries of the following types:
Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right
inclusive where left <= right. Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums
between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ...
+ nums[right]).

Example 1:
Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 *
*/
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SegTreeNode{
    public:
      SegTreeNode(int start, int end, int sum, SegTreeNode *left = nullptr,
                  SegTreeNode *right = nullptr)
          : start(start), end(end), sum(sum), left(left), right(right) {
        cout << "ctor segTreeNode now.\n";
      }
      SegTreeNode(const SegTreeNode &) = delete; // remove the copy
                                                 // constructor
      SegTreeNode &
      operator=(const SegTreeNode &) = delete; // remove the operator=
      ~SegTreeNode() {
        cout << "dtor segTreeNode now.\n";
        delete right;
        delete left;
        left = right = nullptr;
      }
        int start;
        int end;
        int sum;
        SegTreeNode* left;
        SegTreeNode* right;
};

class NumArray {
private:
  std::unique_ptr<SegTreeNode> m_root;
  vector<int> m_nums;

  SegTreeNode *buildTree(int start, int end) {
    if ((start == end)) {
      return new SegTreeNode(start, end, m_nums[start]);
    }
    int mid = start + (end - start) / 2;
    auto left = buildTree(start, mid);
    auto right = buildTree(mid + 1, end);
    return new SegTreeNode(start, end, left->sum + right->sum, left, right);
  }
  void updateTree(SegTreeNode *root, int idx, int val) {
    if (root->start == idx && root->end == idx) {
      root->sum = val;
      return;
    }
    int mid = root->start + (root->end - root->start) / 2;
    if (idx <= mid)
      updateTree(root->left, idx, val);
    else
      updateTree(root->right, idx, val);
    root->sum = root->left->sum + root->right->sum;
  }

  int sumRange(SegTreeNode *root, int i, int j) {
    if (root->start == i && root->end == j)
      return root->sum;
    int mid = root->start + (root->end - root->start) / 2;
    if (i <= mid)
      return sumRange(root->left, i, j);
    else if (j > mid)
      return sumRange(root->right, i, j);
    else
      return sumRange(root->left, i, mid) + sumRange(root->right, mid + 1, j);
  }

public:
  NumArray(vector<int> &&nums) {
    m_nums.swap(nums);
    m_root.reset(buildTree( 0, m_nums.size() - 1));
  }

  void update(int index, int val) { updateTree(m_root.get(), index, val); }

  int sumRange(int left, int right) {
    return sumRange(m_root.get(), left, right);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
  NumArray numArray{vector<int>{1, 3, 5}};
  cout << numArray.sumRange(0, 2) << '\n';
  numArray.update(1, 4);
  cout << numArray.sumRange(0, 2) << '\n';
}