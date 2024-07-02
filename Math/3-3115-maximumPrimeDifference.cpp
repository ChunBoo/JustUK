/***
 * You are given an integer array nums.

Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.

 

Example 1:

Input: nums = [4,2,9,5,3]

Output: 3

Explanation: nums[1], nums[3], and nums[4] are prime. So the answer is |4 - 1| = 3.

Example 2:

Input: nums = [4,8,2,8]

Output: 0

Explanation: nums[2] is prime. Because there is just one prime number, the answer is |2 - 2| = 0.

 

Constraints:

1 <= nums.length <= 3 * 105
1 <= nums[i] <= 100
The input is generated such that the number of prime numbers in the nums is at least one.
 */

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        const int n=nums.size();
        if(n<=1)
            return 0;

        int i=0;
        while(!isPrime(nums[i])){
            i++;
        }
        int j=n-1;
        while(!isPrime(nums[j])){
            j--;
        }
        return j-i;
        // map<int,int> m;
        // for(int i=0;i<n;i++){
        //     if(isPrime(nums[i])){
        //         m[i]=nums[i];
        //     }
        // }
        // int minPos=n, maxPos=0;

        // for(auto &[p,v]:m){
        //     cout<<p<<'\n';
        //     if(p>=0){
        //         if(p<minPos){
        //             minPos=p;
        //         }}
        //         if(p>maxPos){
        //             maxPos=p;
        //         }
            
        // }
        // return maxPos-minPos;
    }
private:
    bool isPrime(int num){
        if(num<=1){
            return false;
        }

        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
};