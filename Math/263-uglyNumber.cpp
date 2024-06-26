/**
 * An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return true if n is an ugly number.
Example 1:
Input: n = 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 * 
*/
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool isUgly(int n) {
        if(n==0)
            return false;
        vector<int> factors{2,3,5};
        for(const auto& i:factors)
            while(n%i==0) n/=i;
        return n==1;
    }
};

int main()
{
    cout<<Solution().isUgly(14);
}