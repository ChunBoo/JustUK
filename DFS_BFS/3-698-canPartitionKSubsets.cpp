// class Solution {
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int s=accumulate(nums.begin(),nums.end(),0);
//         if(s%k!=0)
//             return false;
//         sort(nums.begin(),nums.end());
//         return dfs(nums,s/k,0,k,0);
//     }
// private:
//     bool dfs(const vector<int>& nums,int target,int cur,int k,int used)
//     {
//         if(k==0) 
//             return used==(1<<nums.size())-1;
//         for(int i=0;i<nums.size();++i)
//         {
//             if(used&(1<<i))
//                 continue;
//             int t=cur+nums[i];
//             if(t>target)
//                 break;
//             int newUsed=used|(1<<i);
//             if(t==target&&dfs(nums,target,0,k-1,newUsed))
//                 return true;
//             else if(dfs(nums,target,t,k,newUsed))
//                 return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;    
    sort(nums.rbegin(), nums.rend());    
    return dfs(nums, sum / k, 0, k, 0);
  }
private:
  bool dfs(const vector<int>& nums, int target, int cur, int k, int used) {
    if (k == 0) return used == (1 << nums.size()) - 1;
    for (int i = 0; i < nums.size(); ++i) {
      if (used & (1 << i)) continue;
      int t = cur + nums[i];
      if (t > target) break; // Important
      int new_used = used | (1 << i);
      if (t == target && dfs(nums, target, 0, k - 1, new_used)) return true; 
      else if (dfs(nums, target, t, k, new_used)) return true;
    }
    return false;
  }  
};


class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        sort(nums.rbegin(),nums.rend());//从大到小放数字      
        if(sum%k!=0) return false;
        int target=sum/k;//每个桶的容量
        vector<int> buckets(k,target);//k个桶每个桶可以容纳target的数
        return dfs(nums,buckets,k,0);
    }
    bool dfs(vector<int>& nums,vector<int>& buckets,int k,int index){
        if(index>=nums.size()) return true;//如果把数字都分完了
        for(int i=0;i<k;i++){
            if(nums[index]>buckets[i]) continue; //如果当前数字大于桶的容量
            if(i>0&&buckets[i]==buckets[i-1]) continue;
            buckets[i]-=nums[index];
            if(dfs(nums,buckets,k,index+1)) return true;
            buckets[i]+=nums[index]; //不能不回溯，因为有放错桶的可能
        }      
        return false;
    }
};