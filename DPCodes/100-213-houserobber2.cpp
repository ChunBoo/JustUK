


#include<iostream>
#include<vector>
#include<cmath>

using std::cout;
using VEC=std::vector<int>;
/**
 * @brief 首先考虑最简单的情况。如果只有一间房屋，则偷窃该房屋，可以偷窃到最高总金额。如果只有两间房屋，则由于两间房屋相邻，不能同时偷窃，只能偷窃其中的一间房屋，因此选择其中金额较高的房屋进行偷窃，可以偷窃到最高总金额。

注意到当房屋数量不超过两间时，最多只能偷窃一间房屋，因此不需要考虑首尾相连的问题。如果房屋数量大于两间，就必须考虑首尾相连的问题，第一间房屋和最后一间房屋不能同时偷窃。

如何才能保证第一间房屋和最后一间房屋不同时偷窃呢？如果偷窃了第一间房屋，则不能偷窃最后一间房屋，因此偷窃房屋的范围是第一间房屋到最后第二间房屋；如果偷窃了最后一间房屋，则不能偷窃第一间房屋，因此偷窃房屋的范围是第二间房屋到最后一间房屋。

假设数组 nums\textit{nums}nums 的长度为 nnn。如果不偷窃最后一间房屋，则偷窃房屋的下标范围是 [0,n−2][0, n-2][0,n−2]；如果不偷窃第一间房屋，则偷窃房屋的下标范围是 [1,n−1][1, n-1][1,n−1]。在确定偷窃房屋的下标范围之后，即可用第 198 题的方法解决。对于两段下标范围分别计算可以偷窃到的最高总金额，其中的最大值即为在 nnn 间房屋中可以偷窃到的最高总金额。

假设偷窃房屋的下标范围是 [start,end][\textit{start},\textit{end}][start,end]，用 dp[i]\textit{dp}[i]dp[i] 表示在下标范围 [start,i][\textit{start},i][start,i] 内可以偷窃到的最高总金额，那么就有如下的状态转移方程：

dp[i]=max⁡(dp[i−2]+nums[i],dp[i−1])\textit{dp}[i] = \max(\textit{dp}[i-2]+\textit{nums}[i], \textit{dp}[i-1])
dp[i]=max(dp[i−2]+nums[i],dp[i−1])
边界条件为：

{dp[start]=nums[start]只有一间房屋，则偷窃该房屋dp[start+1]=max⁡(nums[start],nums[start+1])只有两间房屋，偷窃其中金额较高的房屋\begin{cases} \textit{dp}[\textit{start}] = \textit{nums}[\textit{start}] & 只有一间房屋，则偷窃该房屋 \\ \textit{dp}[\textit{start}+1] = \max(\textit{nums}[\textit{start}], \textit{nums}[\textit{start}+1]) & 只有两间房屋，偷窃其中金额较高的房屋 \end{cases}
{ 
dp[start]=nums[start]
dp[start+1]=max(nums[start],nums[start+1])
​
  
只有一间房屋，则偷窃该房屋
只有两间房屋，偷窃其中金额较高的房屋
​
 
计算得到 dp[end]\textit{dp}[\textit{end}]dp[end] 即为下标范围 [start,end][\textit{start},\textit{end}][start,end] 内可以偷窃到的最高总金额。

分别取 (start,end)=(0,n−2)(\textit{start},\textit{end})=(0,n-2)(start,end)=(0,n−2) 和 (start,end)=(1,n−1)(\textit{start},\textit{end})=(1,n-1)(start,end)=(1,n−1) 进行计算，取两个 dp[end]\textit{dp}[\textit{end}]dp[end] 中的最大值，即可得到最终结果。

根据上述思路，可以得到时间复杂度 O(n)O(n)O(n) 和空间复杂度 O(n)O(n)O(n) 的实现。考虑到每间房屋的最高总金额只和该房屋的前两间房屋的最高总金额相关，因此可以使用滚动数组，在每个时刻只需要存储前两间房屋的最高总金额，将空间复杂度降到 O(1)O(1)O(1)。


 * 
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n=nums.size();
        if(n==1)
            return nums[0];
        else if(n==2)
            return max(nums[0],nums[1]);
        // vector<int> dp(n,0);
        // for(int i=0;i<n;++i)
        //     dp[i]=max((i>1?dp[i-2]:0)+nums[i],(i>0?dp[i-1]:0));
        // return min(dp[n-1],dp[n-2]);
        // // return dp[n-1];
        return std::max(dfs(0,n-2,nums),dfs(1,n-1,nums));
    }
private:
    int dfs(int i,int j,const vector<int>& nums)
    {
        // if(j<i)
        //     return 0;
        // return max(dfs(i,j-2,nums)+nums[j],dfs(i,j-1,nums));
        int first=nums[i],second=max(nums[i],nums[i+1]);
        for(int ii=i+2;ii<=j;++ii){
            int tmp=second;
            second=max(first+nums[ii],second);
            first=tmp;
        }
        return second;
    }

};

int dp(int i,int j,const VEC& nums)
{
    if(j<i)
        return 0;
    
    return std::max(dp(i,j-2,nums)+nums[j],dp(i,j-1,nums));
}

int robber2(const VEC& nums)
{
    int sz=nums.size();
    if(sz==1)
        return nums[0];
    return std::max(dp(0,sz-2,nums),dp(1,sz-1,nums));
}

int main()
{
    VEC nums{2,3,2};
    cout<<robber2(nums);
}