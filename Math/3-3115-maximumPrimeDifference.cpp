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
#include<iostream>
#include<vector>
#include<map>
using namespace std;


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
    }
    int foo(vector<int>& nums){
        const int n=nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            if(isPrime(nums[i])){
                m[i]=nums[i];
            }
        }
        auto last=m.rbegin();
        auto start=m.begin();
        if(last!=m.rend()){
            return last->first - start->first;
        }else{
            return 1;
        }
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

int main(){
    vector<int> nums{4,2,9,5,3},nums2{ 4,8,2,8};

    cout<<Solution().foo(nums2);
}