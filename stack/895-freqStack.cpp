class FreqStack {
public:
    FreqStack() {

    }
    
    void push(int val) {
        auto it=freq_.find(val);
        if(it==freq_.end())
        {
            it=freq_.emplace(val,0).first;
        }
        int freq=++it->second;
        if(stacks_.size()<freq) stacks_.push_back({});
        stacks_[freq-1].push(val);
    }
    
    int pop() {
        int x=stacks_.back().top();
        stacks_.back().pop();
        if(stacks_.back().empty())
            stacks_.pop_back();
        auto it=freq_.find(x);
        if(!(--it->second))
            freq_.erase(it);
        return x;
    }
private:
    vector<stack<int>> stacks_;
    unordered_map<int,int> freq_;
    
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */