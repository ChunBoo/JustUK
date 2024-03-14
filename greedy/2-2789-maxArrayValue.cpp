/**
 * @file 2-2789-maxArrayValue.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * You are given a 0-indexed array nums consisting of positive integers.

You can do the following operation on the array any number of times:

Choose an integer i such that 0 <= i < nums.length - 1 and nums[i] <= nums[i + 1]. Replace the element nums[i + 1] with nums[i] + nums[i + 1] and delete the element nums[i] from the array.
Return the value of the largest element that you can possibly obtain in the final array.

 

Example 1:

Input: nums = [2,3,7,9,3]
Output: 21
Explanation: We can apply the following operations on the array:
- Choose i = 0. The resulting array will be nums = [5,7,9,3].
- Choose i = 1. The resulting array will be nums = [5,16,3].
- Choose i = 0. The resulting array will be nums = [21,3].
The largest element in the final array is 21. It can be shown that we cannot obtain a larger element.
Example 2:

Input: nums = [5,3,3]
Output: 11
Explanation: We can do the following operations on the array:
- Choose i = 1. The resulting array will be nums = [5,6].
- Choose i = 0. The resulting array will be nums = [11].
There is only one element in the final array, which is 11.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
 */

/**
 从 iii 开始，只要 nums[i−1]≤nums[i]\textit{nums}[i-1] \le \textit{nums}[i]nums[i−1]≤nums[i]，就不断向左合并数字。

例如示例 1 从 i=3i=3i=3 开始，可以一直向左合并到 i=0i=0i=0。

[2,3,7‾,9‾,3]→[2,3‾,16‾,3]→[2‾,19‾,3]→[21,3][2,3,\underline{7},\underline{9},3]\rightarrow[2,\underline{3},\underline{16},3]\rightarrow[\underline{2},\underline{19},3]\rightarrow[21,3]
[2,3, 
7
​
 , 
9
​
 ,3]→[2, 
3
​
 , 
16
​
 ,3]→[ 
2
​
 , 
19
​
 ,3]→[21,3]
枚举从 i=0,1,2,⋯ ,n−1i=0,1,2,\cdots,n-1i=0,1,2,⋯,n−1 开始向左合并，取合并结果的最大值作为答案。

时间复杂度为 O(n2)\mathcal{O}(n^2)O(n 
2
 )，太慢了。

优化
如果我们从 i=n−1i=n-1i=n−1 开始向左合并，合并到 j (j>0)j\ (j > 0)j (j>0) 停止，这意味着

nums[j−1]>nums[j]+nums[j+1]+⋯+nums[n−1]\textit{nums}[j-1] > \textit{nums}[j] + \textit{nums}[j+1] + \cdots + \textit{nums}[n-1]
nums[j−1]>nums[j]+nums[j+1]+⋯+nums[n−1]
所以从 i=n−2,n−3,⋯ ,ji=n-2,n-3,\cdots,ji=n−2,n−3,⋯,j 开始向左合并，是不会合并出更大的数的，因为 nums\textit{nums}nums 中的元素都是正数，这样合并出来的数字只会更小，永远不会比 nums[j−1]\textit{nums}[j-1]nums[j−1] 更大。

所以无需枚举 i=n−2,n−3,⋯ ,ji=n-2,n-3,\cdots,ji=n−2,n−3,⋯,j，而是直接从 i=j−1i=j-1i=j−1 开始向左合并，并且合并出的数字一定比从 i=n−1i=n-1i=n−1 开始更大。

算法
初始化元素和 sum=nums[n−1]\textit{sum} = \textit{nums}[n-1]sum=nums[n−1]，表示从 n−1n-1n−1 开始向左合并。
从 i=n−2i=n-2i=n−2 开始倒着遍历数组。
如果 nums[i]≤sum\textit{nums}[i] \le \textit{sum}nums[i]≤sum，那么就合并，把 sum\textit{sum}sum 增加 nums[i]\textit{nums}[i]nums[i]。
如果 nums[i]>sum\textit{nums}[i] > \textit{sum}nums[i]>sum，无法合并，并且这意味着从 iii 开始向左合并可以得到比 sum\textit{sum}sum 更大的元素和，所以直接更新 sum=nums[i]\textit{sum} = \textit{nums}[i]sum=nums[i]，继续向左合并。
遍历结束，返回 sum\textit{sum}sum。


 * 
 */


class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        const int n=nums.size();
        long long sum=nums.back();
        for(int i=n-2;i>=0;i--)
        {
            sum=nums[i]<=sum?nums[i]+sum:nums[i];
        }
        return sum;
    }
};