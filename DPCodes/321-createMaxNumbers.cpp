
/**
 * You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.

Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.

Return an array of the k digits representing the answer.

 

Example 1:

Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
Output: [9,8,6,5,3]
Example 2:

Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
Output: [6,7,6,0,4]
Example 3:

Input: nums1 = [3,9], nums2 = [8,9], k = 3
Output: [9,8,9]
 

Constraints:

m == nums1.length
n == nums2.length
1 <= m, n <= 500
0 <= nums1[i], nums2[i] <= 9
1 <= k <= m + n
*/
class Solution {

private:
    vector<int> maxNumber(const vector<int>& nums,int k)
    {
        if(k==0) return {};
        vector<int> ans;
        int toPop=nums.size()-k;
        for(const int num:nums){
            while(!ans.empty()&&num>ans.back()&&toPop-->0)
                ans.pop_back();
            ans.push_back(num);
        }
        ans.resize(k);
        return ans;
    }

    vector<int> maxNumber(const vector<int>& nums1, const vector<int>& nums2)
    {
        vector<int> ans;
        auto s1=nums1.cbegin();
        auto e1=nums1.cend();
        auto s2=nums2.cbegin();
        auto e2=nums2.cend();
        while(s1!=e1 ||s2!=e2)
            ans.push_back(lexicographical_compare(s1,e1,s2,e2)?*s2++:*s1++);
        return ans;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        const int n1=nums1.size();
        const int n2=nums2.size();
        for(int k1=0;k1<=k;++k1){
            const int k2=k-k1;
            if(k1>n1||k2>n2) continue;
            ans=max(ans,maxNumber(maxNumber(nums1,k1),maxNumber(nums2,k2)));
        }
        return ans;
    }
};