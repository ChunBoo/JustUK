/**
 * We are given hours, a list of the number of hours worked per day for a given employee.

A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.

 

Example 1:

Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
Example 2:

Input: hours = [6,6,6]
Output: 0
 

Constraints:

1 <= hours.length <= 104
0 <= hours[i] <= 16
 * 
*/

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int,int> idx;
        int ans=0,s=0;
        for(int i=0;i<hours.size();++i)
        {
            s+=hours[i]>8?1:-1;
            if(s>0)
                ans=i+1;
            else
            {
            if(!idx.count(s))
                idx[s]=i;
            if(idx.count(s-1))
                ans=max(ans,i-idx[s-1]);
            }
        }
        return ans;
    }
};