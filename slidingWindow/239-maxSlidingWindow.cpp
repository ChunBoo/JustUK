class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i=k-1;i<nums.size();++i)
            ans.push_back(*max_element(nums.begin()+i-(k-1),nums.begin()+i+1));
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> win;
        for(int i=0;i<nums.size();++i){
            win.insert(nums[i]);
            if(i-(k-1)>=0)
            {
                ans.push_back(*win.rbegin());
                win.erase(win.equal_range(nums[i-k+1]).first);
            }
        }
        return ans;
    }
};

class MonotonicQueue{
    private:
        deque<int> data_;
    public:
        void push(int e){
            while(!data_.empty()&&e>data_.back())
                data_.pop_back();
            data_.push_back(e);
        }
        void pop()
        {
            data_.pop_front();
        }
        int max() {return data_.front();}
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue q;
        vector<int> ans;
        for(int i=0;i<nums.size();++i){
            q.push(nums[i]);
            if(i-k+1>=0){
                ans.push_back(q.max());
            if(nums[i-k+1]==q.max())  q.pop();
        }
        }
        return ans;
    }
};