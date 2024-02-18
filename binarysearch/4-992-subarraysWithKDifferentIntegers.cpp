/**
 * Given an array A of positive integers, call a (contiguous, not necessarily
distinct) subarray of A good if the number of different integers in that
subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.

Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1],
[1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]. Example 2:

Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3],
[2,1,3], [1,3,4]. Note:

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length
Solution: Two pointers + indirection
Let f(x) denote the number of subarrays with x or less distinct numbers.
ans = f(K) – f(K-1)
It takes O(n) Time and O(n) Space to compute f(x)
*/

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        auto subArrays=[&nums](int k)
        {
            vector<int> count(nums.size()+1);
            int ans=0;
            int i=0;
            for (size_t j = 0; j < nums.size(); ++j) {
              if (count[nums[j]]++ == 0)
                --k;
              while (k < 0)
                if (--count[nums[i++]] == 0)
                  ++k;
              ans += j - i + 1;
            }
            return ans;
        };
        return subArrays(k)-subArrays(k-1);
    }
};

/*
SOLUTION#2:
To directly count the subarrays with exactly K different integers is hard but to
find the count of subarrays with at most K different integers is easy. So the
idea is to find the count of subarrays with at most K different integers, let it
be C(K), and the count of subarrays with at most (K – 1) different integers, let
it be C(K – 1) and finally take their difference, C(K) – C(K – 1) which is the
required answer. Count of subarrays with at most K different elements can be
easily calculated through the sliding window technique. The idea is to keep
expanding the right boundary of the window till the count of distinct elements
in the window is less than or equal to K and when the count of distinct elements
inside the window becomes more than K, start shrinking the window from the left
till the count becomes less than or equal to K. Also for every expansion, keep
counting the subarrays as right – left + 1 where right and left are the
boundaries of the current window.

reference link
https://www.geeksforgeeks.org/count-of-subarrays-having-exactly-k-distinct-elements/
*/

// C++ implementation of the approach
// #include <bits/stdc++.h>
#include <map>
using namespace std;

// Function to return the count of subarrays
// with at most K distinct elements using
// the sliding window technique
int atMostK(int arr[], int n, int k) {

  // To store the result
  int count = 0;

  // Left boundary of window
  int left = 0;

  // Right boundary of window
  int right = 0;

  // Map to keep track of number of distinct
  // elements in the current window
  map<int, int> map;
  // Loop to calculate the count
  while (right < n) {

    // Calculating the frequency of each
    // element in the current window
    if (map.find(arr[right]) == map.end())
      map[arr[right]] = 0;
    map[arr[right]]++;

    // Shrinking the window from left if the
    // count of distinct elements exceeds K
    while (int(map.size()) > k) {
      map[arr[left]] = map[arr[left]] - 1;
      if (map[arr[left]] == 0)
        map.erase(arr[left]);
      left++;
    }

    // Adding the count of subarrays with at most
    // K distinct elements in the current window
    count += right - left + 1;
    right++;
  }
  return count;
}

// Function to return the count of subarrays
// with exactly K distinct elements
int exactlyK(int arr[], int n, int k) {

  // Count of subarrays with exactly k distinct
  // elements is equal to the difference of the
  // count of subarrays with at most K distinct
  // elements and the count of subararys with
  // at most (K - 1) distinct elements
  return (atMostK(arr, n, k) - atMostK(arr, n, k - 1));
}

// Driver code
int main() {
  int arr[] = {1, 2, 1, 2, 3} ;//{2, 1, 2, 1, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 2;

  cout << (exactlyK(arr, n, k));
}

// int main()
// {
//     vector<int> A = { 1, 2, 1, 2, 3};
//     int K = 2;
//     cout << Solution().subarraysWithKDistinct(A,K);
// }