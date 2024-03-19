class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
     pushSt_.push(x);

    }
    
    int pop() {
        if(popST_.empty()){
            while(!pushSt_.empty()){
                popST_.push(pushSt_.top());
                pushSt_.pop();
            }
        }
        int ans=popST_.top();
        popST_.pop();
        return ans;
    }
    
    int peek() {
               if(popST_.empty()){
            while(!pushSt_.empty()){
                popST_.push(pushSt_.top());
                pushSt_.pop();
            }
        }
        return popST_.top();
    }
    
    bool empty() {
        return popST_.empty()&&pushSt_.empty();
    }
private:
    stack<int> pushSt_;
    stack<int> popST_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */