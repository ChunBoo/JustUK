/**
 * Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.

Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
Example 2:

Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
Note:

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length
Solution: Two pointers + indirection
Let f(x) denote the number of subarrays with x or less distinct numbers.
ans = f(K) – f(K-1)
It takes O(n) Time and O(n) Space to compute f(x)
*/


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        auto subArrays=[&nums](int k)
        {
            vector<int> count(nums.size()+1);
            int ans=0;
            int i=0;
            for(int j=0;j<nums.size();++j){
                if(count[nums[j]]++==0)
                    --k;
                while(k<0)
                    if(--count[nums[i++]]==0)
                        ++k;
                ans+=j-i+1;
            }
            return ans;
        };
        return subArrays(k)-subArrays(k-1);
    }
};