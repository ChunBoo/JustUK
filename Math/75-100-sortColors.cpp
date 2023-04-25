#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using VEC=std::vector<int>;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for (int i = 0; i <= p2; ++i) {
            while (i <= p2 && nums[i] == 2) {
                swap(nums[i], nums[p2]);
                --p2;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                ++p0;
            }
        }
    }
};

int main()
{
    VEC nums{2,2,0,1,1,0};
    Solution().sortColors(nums);
    for(auto &v:nums)
        cout<<v<<',';
}
