#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans{};
        for(int i=0;i<n;++i)
            nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]);
        for(int i=0;i<n;++i)
        {
            if(nums[i]>0)
                ans.push_back(i+1);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums{2,3,1,2,3,5,6};
    // cout<<"t";
    vector<int> res=Solution().findDisappearedNumbers(nums);
    for(auto &v:res)
        cout<<v<<',';
}