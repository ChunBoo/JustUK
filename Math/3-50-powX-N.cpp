//https://oi-wiki.org/math/binary-exponentiation/
/**
 * @brief 
 * Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
 */

class Solution {

public:
    double myPow(double x, int n) {

        long long N=n;
        return N>=0?binpow(x,N):1.0/binpow(x,-N);
    }
private:
double binpow(double a, int b) {
  if (b == 0) return 1;
  double res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
};