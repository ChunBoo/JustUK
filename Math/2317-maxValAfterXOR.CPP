/**
 * You are given a 0-indexed integer array nums. In one operation, select any non-negative integer x and an index i, then update nums[i] to be equal to nums[i] AND (nums[i] XOR x).

Note that AND is the bitwise AND operation and XOR is the bitwise XOR operation.

Return the maximum possible bitwise XOR of all elements of nums after applying the operation any number of times.

Example 1:

Input: nums = [3,2,4,6]
Output: 7
Explanation: Apply the operation with x = 4 and i = 3, num[3] = 6 AND (6 XOR 4) = 6 AND 2 = 2.
Now, nums = [3, 2, 4, 2] and the bitwise XOR of all the elements = 3 XOR 2 XOR 4 XOR 2 = 7.
It can be shown that 7 is the maximum possible bitwise XOR.
Note that other operations may be used to achieve a bitwise XOR of 7.
Example 2:

Input: nums = [1,2,3,9,2]
Output: 11
Explanation: Apply the operation zero times.
The bitwise XOR of all the elements = 1 XOR 2 XOR 3 XOR 9 XOR 2 = 11.
It can be shown that 11 is the maximum possible bitwise XOR.
Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 108
Solution: Bitwise OR
The maximum possible number MAX = nums[0] | nums[1] | … | nums[n – 1].

We need to prove:
1) MAX is achievable.
2) MAX is the largest number we can get.

nums[i] AND (nums[i] XOR x) means that we can turn any 1 bits to 0 for nums[i].

1) If the i-th bit of MAX is 1, which means there are at least one number with i-th bit equals to 1, however, for XOR, if there are even numbers with i-th bit equal to one, the final results will be 0 for i-th bit, we get a smaller number. By using the operation, we can choose one of them and flip the bit.

**1** XOR **1** XOR **1** XOR **1** = **0** =>
**0** XOR **1** XOR **1** XOR **1** = **1**

2) If the i-th bit of MAX is 0, which means the i-th bit of all the numbers is 0, there is nothing we can do with the operation, and the XOR will be 0 as well.
e.g. **0** XOR **0** XOR **0** XOR **0** = **0**

Time complexity: O(n)
Space complexity: O(1)
*/

1
2
3
4
5
6
7
// Author: Huahua
class Solution {
public:
  int maximumXOR(vector<int>& nums) {
    return reduce(begin(nums), end(nums), 0, bit_or());
  }
};