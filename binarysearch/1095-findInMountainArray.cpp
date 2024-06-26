/*
(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

 

Example 1:

Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
Example 2:

Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
 

Constraints:

3 <= mountain_arr.length() <= 104
0 <= target <= 109
0 <= mountain_arr.get(index) <= 109
*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
       const int n=mountainArr.length();
       auto binSearch=[&](int l,int r, function<bool(int)> cond){
           while(l<r){
               int m=l+(r-l)/2;
               if(cond(m)) r=m;
               else l=m+1;
           }
           return l;
       };
       int p=binSearch(0,n-1,[&](int i)->bool{
           return mountainArr.get(i)>mountainArr.get(i+1);
       });

       int l=binSearch(0,p,[&](int i)->bool{
           return mountainArr.get(i)>=target;
       });
       if(mountainArr.get(l)==target) return l;
       int r=binSearch(p,n-1,[&](int i)->bool{
           return mountainArr.get(i)<=target;
       });

       if(mountainArr.get(r)==target) return r;
       return -1;
    }
};