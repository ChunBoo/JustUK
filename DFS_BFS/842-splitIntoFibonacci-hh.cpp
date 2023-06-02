/**
 * 
 * You are given a string of digits num, such as "123456579". We can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list f of non-negative integers such that:

0 <= f[i] < 231, (that is, each integer fits in a 32-bit signed integer type),
f.length >= 3, and
f[i] + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2.
Note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from num, or return [] if it cannot be done.

Example 1:

Input: num = "1101111"
Output: [11,0,11,11]
Explanation: The output [110, 1, 111] would also be accepted.

*/

class Solution{
    public:
        vector<int> splitIntoFibonacci(string s)
        {
            const int n=s.size();
            vector<int> nums;
            function<bool(int)> dfs=[&](int pos){
                if(pos==n) return nums.size()>=3;
                int max_len=s[pos]=='0'?1:10;
                long num=0;
                for(int i=pos;i<min(pos+max_len,n);++i){
                    num=num*10+(s[i]-'0');
                    if(num>INT_MAX) break;
                    if(nums.size()>=2){
                        long sum=nums.rbegin()[0];
                        sum+=nums.rbegin()[1];
                        if(num>sum) break;
                        else if(num<sum) continue;
                    }
                    nums.push_back(num);
                    if(dfs(i+1)) return true;
                    nums.pop_back();
                }
                return false;
            };
            dfs(0);
            return nums;
        }
};