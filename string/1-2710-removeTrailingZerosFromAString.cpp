/**
 * @brief 
 * Given a positive integer num represented as a string, return the integer num without trailing zeros as a string.

 

Example 1:

Input: num = "51230100"
Output: "512301"
Explanation: Integer "51230100" has 2 trailing zeros, we remove them and return integer "512301".
Example 2:

Input: num = "123"
Output: "123"
Explanation: Integer "123" has no trailing zeros, we return integer "123".
 

Constraints:

1 <= num.length <= 1000
num consists of only digits.
num doesn't have any leading zeros.
 * 
 */

class Solution {
public:
    string removeTrailingZeros(string num) {
        // const int n=num.size();
        // for(int i=n-1;i>=0;i--){
        //     if(num[i]=='0'){
        //         continue;
        //     }
        //     else{
        //         return num.substr(0,i+1);
        //     }
        // }
        // return "";
         return num.substr(0, num.find_last_not_of('0') + 1);
    }
};