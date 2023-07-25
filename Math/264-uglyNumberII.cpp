/**
 * An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.
Example 1:
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
 * 
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums;
        for(long a=1;a<=INT_MAX;a*=2)
            for(long b=a;b<=INT_MAX;b*=3)
                for (long c=b;c<=INT_MAX;c*=5)
                    nums.push_back(c);
        std::sort(nums.begin(),nums.end());
        return nums[n-1];
    }
};

class Solution2 {
public:
    int nthUglyNumber(int n) {
        static vector<int> nums;
        if(nums.empty()){
        for(long a=1;a<=INT_MAX;a*=2)
            for(long b=a;b<=INT_MAX;b*=3)
                for (long c=b;c<=INT_MAX;c*=5)
                    nums.push_back(c);
        std::sort(nums.begin(),nums.end());
        }
        return nums[n-1];
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> nums{1};
        static int i2=0;
        static int i3=0;
        static int i5=0;
        while(nums.size()<n){
            const int nxt2=nums[i2]*2;
            const int nxt3=nums[i3]*3;
            const int nxt5=nums[i5]*5;
            const int next=min(nxt2,min(nxt3,nxt5));
            if(next==nxt2) ++i2;
            if(next==nxt3) ++i3;
            if(next==nxt5) ++i5;
            nums.push_back(next);
        }
        return nums[n-1];
    }
};