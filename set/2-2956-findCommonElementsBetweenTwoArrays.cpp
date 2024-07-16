/**
 * @brief You are given two integer arrays nums1 and nums2 of sizes n and m, respectively. Calculate the following values:

answer1 : the number of indices i such that nums1[i] exists in nums2.
answer2 : the number of indices i such that nums2[i] exists in nums1.
Return [answer1,answer2].
Example 2:

Input: nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]

Output: [3,4]

Explanation:

The elements at indices 1, 2, and 3 in nums1 exist in nums2 as well. So answer1 is 3.

The elements at indices 0, 1, 3, and 4 in nums2 exist in nums1. So answer2 is 4.

Example 3:

Input: nums1 = [3,4,2,3], nums2 = [1,5]

Output: [0,0]

Explanation:

No numbers are common between nums1 and nums2, so answer is [0,0].
 
 * 
 */
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        const int n1=nums1.size(), n2=nums2.size();
        vector<int> ans(2,0);
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int cnt1=0;
        for(int i=0;i<n1;i++){
            if(find(nums2.begin(),nums2.end(),nums1[i])!=nums2.end()){
                cnt1+=1;
            }
        }
        ans[0]=cnt1;
        int cnt2=0;
        for(int i=0;i<n2;i++){
            if(find(begin(nums1),end(nums1),nums2[i])!=nums1.end()){
                cnt2++;
            }
        }
        ans[1]=cnt2;
        // return ans;
        /*
        unordered_set<int> s1{begin(nums1),end(nums1)};
        unordered_set<int> s2{begin(nums2),end(nums2)};

        for(int x:nums1){
            ans[0]+=s2.count(x);
        }
        for(int x:nums2){
            ans[1]+=s1.count(x);
        }
        */
        return ans;
    }
};