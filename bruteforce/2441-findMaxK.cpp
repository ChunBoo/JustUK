class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(nums[i]>0 &&nums[i]==-nums[j])
                    ans=max(ans,nums[i]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(nums[i]==-nums[j])
                    ans=max(ans,abs(nums[i]));
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        std::map<int,int> m;
        for(auto const &v:nums)
            m[v]=1;
        int ans=-1;
        for(auto &[k,v]:m)
        {
            if(m.find(-k)!=m.end())
                ans=max(ans,abs(k));
        }
    return ans;
    }
};

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s{nums.begin(),nums.end()};
        int ans=-1;
        for(auto i:s)
        {
            if(i>0 &&s.count(-i))
                ans=max(ans,i);
        }
        return ans;
    }
};

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s;
        int ans=-1;
        for(auto x:nums){
            if(abs(x)>ans&&s.count(-x))
            {
                ans=abs(x);
            }
        s.insert(x);
        }
        return ans;
    }
};

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0, r=n-1,ans=-1;
        while(l<r)
        {
            if(nums[l]+nums[r]==0)
                return nums[r];
            else if(nums[l]+nums[r]>0)
                r-=1;
            else
                l+=1;
        }
        return ans;
    }
};

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b){
            return abs(a)==abs(b)?a<b:abs(a)>abs(b);
        });
        for(int i=1;i<nums.size();++i)
            if(nums[i]==-nums[i-1]) return nums[i];
        return -1;
    }
};