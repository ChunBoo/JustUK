/**
 * You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         for(auto num:matrix)
//         {
//          cout<<'\n';
//          for(auto v:num)
//             cout<<v<<',';
//          if(searchMatrix(num,target))
//             return true;
        
//         }
//         return false;
//     }
// private:
//     bool searchMatrix(const vector<int>& nums,int target)
//     {
//         const int n=nums.size();
//         int l=0,r=n-1;
//         while(l<=r)
//         {
//             int m=l+(r-l)/2;
//             if(nums[m]==target)
//                 return true;
//             else if(nums[m]>target)
//                 r=m-1;
//             else
//                 l=m+1;
//         }
//         return false;
//     }
// };


class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int l = 0;
    int r = matrix.size() * matrix[0].size();
    const int cols = matrix[0].size();
    while (l < r) {
      const int m = l + (r - l) / 2;
      if (matrix[m / cols][m % cols] == target) {
        return true;
      } else if (matrix[m / cols][m % cols] > target) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return false;
  }
};