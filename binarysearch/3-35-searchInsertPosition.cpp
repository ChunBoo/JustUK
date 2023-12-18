/**
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto found=find(begin(nums),end(nums),target);
        if(found!=end(nums))
            return found-begin(nums);
        auto it=upper_bound(begin(nums),end(nums),target);
        if(it!=nums.end())
            return it-begin(nums);
        else
            return nums.size();
    }
};