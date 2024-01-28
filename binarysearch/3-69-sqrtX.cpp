
/**
 * Problem:

Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.

Example 1:

1
2
Input: 4
Output: 2
Example 2:

1
2
3
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842...
 
*/
class Solution {
public:
    int mySqrt(int x) {
    //     if(x<=1)
    //         return x;
    //     for(long long s=1;s<=x;++s)
    //     {
    //         if(s*s>x)
    //             return s-1;
    //     }
    //     return -1;
    // }
    if(x<=1)
        return x;
    long l=1;
    long r=static_cast<long>(x);

    while(l<r)
    {
        long m=l+(r-l)/2;
        if(m*m>x)
            r=m;
        else
            l=m+1;
    }
    return l-1;
    }
};