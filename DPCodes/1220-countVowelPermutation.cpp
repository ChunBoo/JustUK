
/**
 * Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
 * 
*/

class Solution {
public:
    int countVowelPermutation(int n) {
        constexpr int kMod=1e9+7;
        long a=1,e=1,i=1,o=1,u=1;
        for(int k=2;k<=n;++k){
            long aa=(e+i+u)%kMod;
            long ee=(a+i)%kMod;
            long ii=(e+o)%kMod;
            long oo=(i)%kMod;
            long uu=(i+o)%kMod;
            a=aa;
            e=ee;
            i=ii;
            o=oo;
            u=uu;
        }
        return (a+e+i+o+u)%kMod;
    }
};