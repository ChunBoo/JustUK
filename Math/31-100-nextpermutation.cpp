#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using VEC=vector<int>;

class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        int i=0;
        for (i=nums.size()-2; i >= 0; -- i) { // 从后往前找到第一个相邻升序对
            if (nums[i] < nums[i+1]) break;
        }
        if (i == -1) reverse(nums.begin(),nums.end()); // 无相邻升序对，必定为非递减序列
        else {
            for (int j=nums.size()-1; j >= i+1; -- j) { // 从后往前[i+1,end)找第一个大于a[i]的值
                if (nums[i] < nums[j]) {
                    swap(nums[i],nums[j]); // 交换二者
                    reverse(nums.begin()+i+1,nums.end()); // 反转[i+1,end)，变成升序
                    break;
                }
            }
        }
    }
};

int main()
{
    VEC nums{1,2,4,3};
    Solution().nextPermutation(nums);
    for(auto &v:nums)
        cout<<v<<',';
}