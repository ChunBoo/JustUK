#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(const std::vector<int> &arr) {
  int n = arr.size() + 1; // Since one number is missing
  int xorSum = 0;

  // XOR all numbers from 1 to n+1
  for (int i = 1; i <= n; ++i) {
    xorSum ^= i;
  }

  // XOR the result with all elements in the array
  for (int num : arr) {
    xorSum ^= num;
  }

  // The result is the missing number
  return xorSum;
}

int findDuplicate(const std::vector<int> &nums) {
  int xorSum = 0;
  int n = nums.size() - 1; // Adjusting for the extra duplicate in the size

  // XOR all elements from 1 to n-1
  for (int i = 1; i <= n; ++i) {
    xorSum ^= i;
  }

  // XOR the result with all elements in the array
  for (int num : nums) {
    xorSum ^= num;
  }

  // The remaining number is the duplicate
  return xorSum;
}

int main() {
  std::vector<int> nums = {1, 3, 4, 2, 2}; // Example array
  std::cout << "The duplicate number is " << findDuplicate(nums) << std::endl;
  return 0;
}
// int main() {
//   std::vector<int> arr = {1, 2, 4, 5, 6}; // Example array
//   std::cout << "The missing number is " << findMissingNumber(arr) << std::endl;
//   return 0;
// }