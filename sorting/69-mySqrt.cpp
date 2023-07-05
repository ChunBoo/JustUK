
/**
 * 
 Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
 The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 * 
*/
#include<iostream>
using std::cout;
class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1)
            return x;
        long long l=0, r=x;  //here is long long,not int, as might has overflow risk
        while(l<r)
        {
            long long m=l+(r-l)/2;
            if(m*m>x)
                r=m;
            else
                l=m+1;
        }
        return l-1;
    }
};


int main()
{
    cout<<Solution().mySqrt(8);
}