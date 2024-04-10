/**
 * @brief You are given a binary string binary consisting of only 0's or 1's. You can apply each of the following operations any number of times:

Operation 1: If the number contains the substring "00", you can replace it with "10".
For example, "00010" -> "10010"
Operation 2: If the number contains the substring "10", you can replace it with "01".
For example, "00010" -> "00001"
Return the maximum binary string you can obtain after any number of operations. Binary string x is greater than binary string y if x's decimal representation is greater than y's decimal representation.

 

Example 1:

Input: binary = "000110"
Output: "111011"
Explanation: A valid transformation sequence can be:
"000110" -> "000101" 
"000101" -> "100101" 
"100101" -> "110101" 
"110101" -> "110011" 
"110011" -> "111011"
Example 2:

Input: binary = "01"
Output: "01"
Explanation: "01" cannot be transformed any further.
 * 
 */
// class Solution {
// public:
//     string maximumBinaryString(string binary) {
//         // int n =binary.size();
//         // int j=0;
//         // for(int i=0;i<n;i++)
//         // {
//         //     if(binary[i]=='0'){
//         //         while(j<=i||(j<n&&binary[j]=='1'))
//         //             j++;
                
//         //         if(j<n){
//         //             binary[j]='1';
//         //             binary[i]='1';
//         //             binary[i+1]='0';
//         //         }
//         //     }
//         // }
//         // return binary;
//     }
// };


// class Solution {
// public:
//   string maximumBinaryString(string s) {
//     const int n = s.length();
//     int l = 0;
//     int z = 0;
//     for (char& c : s) {
//       if (c == '0') {
//         ++z;
//       } else if (z == 0) { // leading 1s      
//         ++l;
//       }
//       c = '1';
//     }
//     if (l != n) s[l + z - 1] = '0';
//     return s;
//   }
// };


class Solution {
public:
    string maximumBinaryString(string binary) {
        auto p = ranges::find(binary, '0');
        if (p == binary.end()) return binary;
        int n = binary.size(), c = count(p, binary.end(), '1');
        return string(n-1-c, '1') + '0' + string(c, '1');
    }
};