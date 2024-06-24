/**
 * Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
 

Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        // vector<int> ans(n);
        // stack<int> s{{end(nums),begin(nums)}};
        // stack<int> s;
        // for(int i=n-1;i>-1;--i)
        //     s.push(nums[i]);
        int temp=0;
        for(int i=n-1;i>-1;--i)
        {
            while(!s.empty()&&s.top()<=nums[i])
            {
                s.pop();
            }
           temp=nums[i];
           nums[i]=s.empty()?-1:s.top();
           s.push(temp);
        }
        return nums;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            int x=nums[i%n];
            while(!st.empty()&&x>=st.top()){
                st.pop();
            }
            if(i<n&&!st.empty()){
                ans[i]=st.top();
            }
            st.push(x);
        }
        return ans;
    }
};