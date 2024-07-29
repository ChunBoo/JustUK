/***
 * You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.

 

Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.
Example 2:

Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
Example 3:

Input: ops = ["1","C"]
Output: 0
Explanation:
"1" - Add 1 to the record, record is now [1].
"C" - Invalidate and remove the previous score, record is now [].
Since the record is empty, the total sum is 0.
 

Constraints:

1 <= operations.length <= 1000
operations[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 104, 3 * 104].
For operation "+", there will always be at least two previous scores on the record.
For operations "C" and "D", there will always be at least one previous score on the record.
 */

class Solution {
public:
    int calPoints(vector<string>& operations) {
        // stack<int> s;
        // for(string c:operations){
        //     if(c.size()>1){
        //         s.push(stoi(c));
        //     }
        //     else if(c=="C"){
        //         s.pop();
        //     }
        //     else if(c=="D"){
        //         int cur=s.top();
        //         s.push(cur*2);
        //     }
        //     else if(c=="+"){
        //         int top1=s.top();
        //         s.pop();
        //         int top2=s.top();
        //         s.push(top1);
        //         s.push(top1+top2);
        //     }
        //     else{
        //         s.push(stoi(c));
        //     }
        // }
        // int ans=0;
        // while(!s.empty()){
        //     ans+=s.top();
        //     s.pop();
        // }
        // return ans;


        int ans=0;
        vector<int> v;
        for(auto &s:operations){
            int n=v.size();
            switch(s[0]){
                case '+':
                    ans+=v[n-1]+v[n-2];
                    v.push_back(v[n-1]+v[n-2]);
                    break;
                case 'D':
                    ans+=2*v[n-1];
                    v.push_back(2*v[n-1]);
                    break;
                case 'C':
                    ans-=v[n-1];
                    v.pop_back();
                    break;
                default:
                    ans+=stoi(s);
                    v.push_back(stoi(s));
                    break;
            }
        }
        return ans;
    }
};