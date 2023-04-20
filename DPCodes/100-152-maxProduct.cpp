#include<iostream>
#include<vector>
#include<algorithm>
using std::cout;
using VEC=std::vector<int>;
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector <int> maxF(nums), minF(nums);
        int n=nums.size();
        for (int i = 1; i < n; ++i) {
            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};



int main()
{
    VEC nums{-2,3,-4};
    int res=Solution().maxProduct(nums);
    cout<<res;
}