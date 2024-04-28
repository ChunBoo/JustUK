/***
 * Given an integer n, return a binary string representing its representation in base -2.

Note that the returned string should not have leading zeros unless the string is "0".

 

Example 1:

Input: n = 2
Output: "110"
Explantion: (-2)2 + (-2)1 = 2
Example 2:

Input: n = 3
Output: "111"
Explantion: (-2)2 + (-2)1 + (-2)0 = 3
Example 3:

Input: n = 4
Output: "100"
Explantion: (-2)2 = 4
 

Constraints:

0 <= n <= 109
*/

class Solution {
public:
    string baseNeg2(int n) {
        if(n==0)
            return "0";
        return baseNegK(n,-2);
}
private:
    string baseNegK(int n,int k)
    {
        vector<char> s;
        while(n){
            int r=n%k;
            n/=k;
            if(r<0){
                r-=k;
                n+=1;
            }
            // s+=(r+'0');
            s.push_back(r+'0');
        }
        return {rbegin(s),rend(s)};
    }
};