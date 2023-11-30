/**
 * Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/

class Solution {  //BST
public:
    vector<int> sortArray(vector<int>& nums) {
        multiset<int> s{begin(nums),end(nums)};
        return {s.begin(),s.end()};
    }
};

class Solution {  //merge sorting
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> t(nums.size());
        function<void(int,int)> mergeSort=[&](int l,int r)
        {
            if(l+1>=r) return;
            int m=l+(r-l)/2;
            mergeSort(l,m);
            mergeSort(m,r);
            int i1=l,i2=m;
            int index=0;
            while(i1<m||i2<r)
            {
                if(i2==r||(i1<m&&nums[i1]<nums[i2]))
                    t[index++]=nums[i1++];
                else
                    t[index++]=nums[i2++];
            }
            std::copy(t.begin(),t.begin()+index,nums.begin()+l);
        };
        mergeSort(0,nums.size());
        return nums;
    }
};


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> q{begin(nums),end(nums)};
        int i=nums.size();
        while(!q.empty())
        {
            nums[--i]=q.top();
            q.pop();
        }
        return nums;
    }
};

class Solution {  //count sorting
public:
    vector<int> sortArray(vector<int>& nums) {
        auto [min_it,max_it]=minmax_element(nums.begin(),nums.end());
        int l=*min_it, r=*max_it;
        vector<int> count(r-l+1);
        for(int n:nums) ++count[n-l];
        int index=0;
        for(int i=0;i<count.size();++i)
            while(count[i]--) nums[index++]=i+l;
        return nums;
    }
};