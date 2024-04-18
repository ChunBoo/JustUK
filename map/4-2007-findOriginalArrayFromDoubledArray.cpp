/***
 * An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.

 

Example 1:

Input: changed = [1,3,4,2,6,8]
Output: [1,3,4]
Explanation: One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].
Example 2:

Input: changed = [6,3,0,1]
Output: []
Explanation: changed is not a doubled array.
Example 3:

Input: changed = [1]
Output: []
Explanation: changed is not a doubled array.
 

Constraints:

1 <= changed.length <= 105
0 <= changed[i] <= 105
*/

// class Solution {
// public:
//     vector<int> findOriginalArray(vector<int>& changed) {
//         const int n=changed.size();
//         if(n%2==1||n<2)
//             return {};
        
//         vector<int> ans;
//         std::sort(begin(changed),end(changed));
//         for(auto i:changed)
//             cout<<i<<",";
//         // int pre=0;
//         for(int i=1;i<n;i+=2)
//         {
//             cout<<i<<'-';
//             if(i==1&&(changed[i]==2*changed[0]))
//                 ans.push_back(changed[0]);
//             else if(i>1&&changed[i]==2*changed[i-2]){
//                 ans.push_back(changed[i-1]);
//                 // pre=i;
//             }
//             else if(i==n-1 && changed[i]==2*changed[i-2])
//                 ans.push_back(changed[i-2]);
//             else
//                 return {};
//         }
//         return ans;
//     }
// };

class Solution{
    public: 
        vector<int> findOriginalArray(vector<int>& changed){
            sort(begin(changed),end(changed));
            unordered_map<int,int> count;
            for(int a:changed){
                count[a]++;
            }
            vector<int> ans;
            for(int a:changed){
                if(count[a]==0)
                    continue;
                count[a]--;
                if(count[a*2]==0)
                    return {};
                count[a*2]--;
                ans.push_back(a);
            }
            return ans;
        }
};