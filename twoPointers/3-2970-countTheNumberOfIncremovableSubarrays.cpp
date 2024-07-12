/***
 * You are given a 0-indexed array of positive integers nums.

A subarray of nums is called incremovable if nums becomes strictly increasing on removing the subarray. For example, the subarray [3, 4] is an incremovable subarray of [5, 3, 4, 6, 7] because removing this subarray changes the array [5, 3, 4, 6, 7] to [5, 6, 7] which is strictly increasing.

Return the total number of incremovable subarrays of nums.

Note that an empty array is considered strictly increasing.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 10
Explanation: The 10 incremovable subarrays are: [1], [2], [3], [4], [1,2], [2,3], [3,4], [1,2,3], [2,3,4], and [1,2,3,4], because on removing any one of these subarrays nums becomes strictly increasing. Note that you cannot select an empty subarray.
Example 2:

Input: nums = [6,5,7,8]
Output: 7
Explanation: The 7 incremovable subarrays are: [5], [6], [5,7], [6,5], [5,7,8], [6,5,7] and [6,5,7,8].
It can be shown that there are only 7 incremovable subarrays in nums.
Example 3:

Input: nums = [8,7,6,6]
Output: 3
Explanation: The 3 incremovable subarrays are: [8,7,6], [7,6,6], and [8,7,6,6]. Note that [8,7] is not an incremovable subarray because after removing [8,7] nums becomes [6,6], which is sorted in ascending order but not strictly increasing.
 

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50
 */
#include<vector>
#include<iostream>

using namespace std;
/*
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        const int n=nums.size();
        // int ans=1;
        // int l=0;
        // for(int i=0;i<n;i++){
        //     l=0;
        //     bool isIncremovable=true;
        //     while(l<n-1){
        //         if(l==i){
        //             continue;
        //         }
        //         if((l+1!=i)&&nums[l]>=nums[l+1])
        //         {
        //             isIncremovable=false;
        //             break;
        //         }
        //         l+=1;
        //     }
        //     if(isIncremovable){
        //         ans+=1;
        //     }
        // }
        // return ans;

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isIncreasing(nums,i,j))
                    ans++;
            }
        }
        return ans;
    }
    bool isIncreasing(vector<int>& nums,int l,int r){
        for(int i=1;i<nums.size();i++){
            if(i>=l&&i<=r+1){
                continue;
            }
            if(nums[i]<=nums[i-1]){
                return false;
            }
        }
        if(l-1>=0&&r+1<nums.size()&&nums[r+1]<=nums[l-1]){
            return false;
        }
        return true;
    }
};
*/
/***
 * Solution 1: Two Pointers  https://github.com/doocs/leetcode/blob/main/solution/2900-2999/2970.Count%20the%20Number%20of%20Incremovable%20Subarrays%20I/README_EN.md
According to the problem description, after removing a subarray, the remaining elements are strictly increasing. Therefore, there are several situations:

The remaining elements only include the prefix of the array 
 (which can be empty);
The remaining elements only include the suffix of the array 
;
The remaining elements include both the prefix and the suffix of the array 
.
The second and third situations can be combined into one, that is, the remaining elements include the suffix of the array 
. So there are two situations in total:

The remaining elements only include the prefix of the array 
 (which can be empty);
The remaining elements include the suffix of the array 
.
First, consider the first situation, that is, the remaining elements only include the prefix of the array 
. We can use a pointer 
 to point to the last element of the longest increasing prefix of the array 
, that is, 
, then the number of remaining elements is 
, where 
 is the length of the array 
. Therefore, for this situation, to make the remaining elements strictly increasing, we can choose to remove the following subarrays:

;
;
;
;
;
.
There are 
 situations in total, so for this situation, the number of removed increasing subarrays is 
.

Next, consider the second situation, that is, the remaining elements include the suffix of the array 
. We can use a pointer 
 to point to the first element of the increasing suffix of the array 
. We enumerate 
 as the first element of the increasing suffix in the range 
. Each time, we need to move the pointer 
 to make 
, then the number of removed increasing subarrays increases by 
. When 
, we stop enumerating because the suffix is not strictly increasing at this time.

The time complexity is 
, where 
 is the length of the array 
. The space complexity is 
.

Python3
 */
class Solution2 {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int i = 0, n = nums.size();
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            ++i;
        }
        if (i == n - 1) {
            return n * (n + 1) / 2;
        }
        int ans = i + 2;
        for (int j = n - 1; j > 0; --j) {
            while (i >= 0 && nums[i] >= nums[j]) {
                --i;
            }
            ans += i + 2;
            if (nums[j - 1] >= nums[j]) {
                break;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums{4,2};
    cout<<Solution2().incremovableSubarrayCount(nums);
}