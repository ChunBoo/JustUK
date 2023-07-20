/**
 * 
 * Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.

The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.
Example 2:

Input: arr = [1,1,2]
Output: 3
Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.

 * 
*/
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> cur;
        unordered_set<int> nxt;

        for(int a:arr){
            nxt.clear();
            nxt.insert(a);
            for(int b:cur)
            {
                nxt.insert(a|b);
            }
            cur.swap(nxt);
            ans.insert(begin(cur),end(cur));
        }
        return ans.size();      
    }
};

int main() { 
    vector<int> nums{1, 3, 2};
    cout<<Solution().subarrayBitwiseORs(nums);
 }