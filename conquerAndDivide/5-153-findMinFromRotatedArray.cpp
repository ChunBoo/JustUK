/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

Idea:

Divide and conquer.

Evenly Split the array into two sub-arrays, and find the minimums of them, return the smaller one.

findMin(a[0..n]) = min(findMin(a[0..n/2], a[n/2..n])

Key property:

One of the sub-array will be a sorted array, it takes O(1) to find the minimal element, just the first element.*/


class Solution {
public:
    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size()-1);
    }
    
private:
    int findMin(const vector<int>& num, int l, int r)
    {
        // Only 1 or 2 elements
        if (l+1 >= r) return min(num[l], num[r]);
        
        // Sorted
        if (num[l] < num[r]) return num[l];
        
        int mid = l + (r-l)/2; 
        
        return min(findMin(num, l, mid-1), 
                   findMin(num, mid, r));
    }
};