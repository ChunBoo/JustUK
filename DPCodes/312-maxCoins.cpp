/**
 * You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
*/

class Solution {
private:
    vector<vector<int>> c_;
    int maxCoins(const vector<int>& nums,const int i,const int j){
        if(i>j) return 0;
        if(c_[i][j]>0) return c_[i][j];
        if(i==j) return nums[i-1]*nums[i]*nums[i+1];
        int ans=0;
        for(int k=i;k<=j;++k)
            ans=max(ans,maxCoins(nums,i,k-1)+nums[i-1]*nums[k]*nums[j+1]+ maxCoins(nums,k+1,j));
        c_[i][j]=ans;
        return c_[i][j];

    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        c_=vector<vector<int>>(n+2,vector<int>(n+2,0));
        return maxCoins(nums,1,n);

    }
};

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(begin(nums),1);
        nums.push_back(1);

        vector<vector<int>> c(n+2,vector<int>(n+2,0));

        for(int l=1;l<=n;l++){
            for(int i=1;i<=n-l+1;i++){
                int j=i+l-1;
                for(int k=i;k<=j;k++){
                    c[i][j]=max(c[i][j],c[i][k-1]+nums[i-1]*nums[k]*nums[j+1]+c[k+1][j]);
                }
            }
        }
        return c[1][n];
    }
};