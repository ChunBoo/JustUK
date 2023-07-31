class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i=k-1;i<nums.size();++i)
            ans.push_back(*max_element(nums.begin()+i-k+1,nums.begin()+i+1));
        return ans;
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> window;
        for(int i=0;i<nums.size();++i){
            window.insert(nums[i]);
            if(i-k+1>=0)
            {
                ans.push_back(*window.rbegin());
                window.erase(window.equal_range(nums[i-k+1]).first);
                // window.erase(nums[i-k+1]); //will delete all same elements which is incorrect
            }
        }
        return ans;
    }
};


class MQueue{
    private:
        deque<int> q;
    public:
        void push(int e){
            while(!q.empty()&&e>q.back())  q.pop_back();
            q.push_back(e);
        }
        void pop(){
            q.pop_front();
        }
        int max() const {return q.front();}
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       MQueue q;
       vector<int> ans;
       for(int i=0;i<nums.size();++i){
           q.push(nums[i]);
           if(i-k+1>=0){
               ans.push_back(q.max());
               if(nums[i-k+1]==q.max()) q.pop();
           }
       }
       return ans;
    }
};