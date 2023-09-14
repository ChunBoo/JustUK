/**
 * Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.

Recall that the number of set bits an integer has is the number of 1's present when written in binary.

For example, 21 written in binary is 10101, which has 3 set bits.
 

Example 1:

Input: left = 6, right = 10
Output: 4
Explanation:
6  -> 110 (2 set bits, 2 is prime)
7  -> 111 (3 set bits, 3 is prime)
8  -> 1000 (1 set bit, 1 is not prime)
9  -> 1001 (2 set bits, 2 is prime)
10 -> 1010 (2 set bits, 2 is prime)
4 numbers have a prime number of set bits.
Example 2:

Input: left = 10, right = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
5 numbers have a prime number of set bits.
 

Constraints:

1 <= left <= right <= 106
0 <= right - left <= 104
*/
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

class Solution {
private:
    int bitsCnt(int n){
        int ans=0;
        while(n>0)
        {
            ans+=(n&1);
            n=(n>>1);
        }
        return ans;
    }
    bool isPrimer(int n){
        if(n==1) return false;
        if(n==2) return true;
        for(int i=2;i<sqrt(n)+1;++i)
            if((n%i)==0) return false;
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        if(left>right)
            return 0;
        int ans=0;
        int val=left;
        while(val<=right)
        {
            ans+=(isPrimer(bitsCnt(val)));
            val+=1;
        }
        return ans;
    }
};

class Solution2 {
public:
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        set<int> primes{2,3,5,7,11,13,17,19};
        for(int i=left;i<=right;++i)
        {
            if(primes.count(__builtin_popcountll(i)))
                ans+=1;
        }
        return ans;
    }
};

int main() {
    int left = 6, right = 10;
    cout << Solution().countPrimeSetBits(left, right);
    cout << Solution2().countPrimeSetBits(left, right);
    }