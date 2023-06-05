/**
 * You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

Example 1:
Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.

 * 
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // int n=letters.size();
        // for(int i=0;i<n;++i)
        // {
        //     if(letters[i]>target)
        //         return letters[i];
        // }
        // return letters[0];
        // for(const char c:letters)
        //     if(c>target)
        //         return c;
        // return letters.front();

        int n=letters.size();
        int l=0,r=n;
        while(l<r)
        {
            const int m=l+(r-l)/2;
            if(letters[m]<=target)
                l=m+1;
            else
                r=m;
        }
        return letters[l%n];
    }
};