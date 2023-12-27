#include<iostream>
#include<vector>
using namespace std;
class FenwickTree{
public:
    FenwickTree(int n): sum_(n+1,0){};
    void update(int i,int data)
    {
        while(i<int(sum_.size()))
        {
            sum_[i]+=data;
            i+=lowbit(i);
        }

    };
    int query(int i)
    {
        int sum=0;
        while(i>0)
        {
            sum+=sum_[i];
            i-=lowbit(i);
        }
        return sum;
    }
private:
    vector<int> sum_;
    inline int lowbit(int x){
        return x&(-x);
    }
};
class NumArray {
public:
    NumArray(vector<int>& nums):tree_(nums.size()) {
        nums_=std::move(nums);
        // tree_=FenwickTree(nums.size());
        for(int i=0;i<int(nums_.size());++i)
            tree_.update(i+1,nums[i]);
    }
    
    void update(int index, int val) {
        tree_.update(index+1,val-nums_[index]);
        nums_[index]=val;
    }
    
    int sumRange(int left, int right) {
        return tree_.query(right+1)-tree_.query(left);
    }
private:
    FenwickTree tree_;
    vector<int> nums_;
};


int main()
{
    vector<int> nums{1, 3, 5};
    NumArray test{nums};
    cout<<test.sumRange(0,2);
}
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */