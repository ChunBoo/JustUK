
/**
 * Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Example 1:

Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8

 * 
*/
class SegTreeNode{
    public:
        SegTreeNode(int start,int end,int sum,SegTreeNode* left=nullptr, SegTreeNode* right=nullptr):
            start(start),
            end(end),
            sum(sum),
            left(left),
            right(right){}
        SegTreeNode(const SegTreeNode&)=delete;
        SegTreeNode& operator=(const SegTreeNode&)=delete;
        ~SegTreeNode()
        {
            delete right;
            delete left;
            left=right=nullptr;
        }
        int start;
        int end;
        int sum;
        SegTreeNode* left;
        SegTreeNode* right;
};

class NumArray {
private:
    vector<int> nums_;
    std::unique_ptr<SegTreeNode> root_;
    SegTreeNode* buildTree(int start,int end){
        if(start==end)
            return new SegTreeNode(start,end,nums_[start]);
        int mid=start+(end-start)/2;
        auto left=buildTree(start,mid);;
        auto right=buildTree(mid+1,end);
        auto node=new SegTreeNode(start,end,left->sum+right->sum,left,right);
        return node;
    }
    void updateTree(SegTreeNode* root,int i,int val){
        if(root->start==i &&root->end==i)
        {
            root->sum=val;
            return;
        }
        int mid=root->start+(root->end-root->start)/2;
        if(i<=mid)
            updateTree(root->left,i,val);
        else
            updateTree(root->right,i,val);
        root->sum=root->left->sum+root->right->sum;
    }
    int sumRange(SegTreeNode* root,int i,int j){
        if(i==root->start&&j==root->end){
            return root->sum;
        }
        int mid=root->start+(root->end-root->start)/2;
        if(j<=mid){
            return sumRange(root->left,i,j);
        }
        else if(i>mid)
            return sumRange(root->right,i,j);
        else
            return sumRange(root->left,i,mid)+sumRange(root->right,mid+1,j);
    }
public:
    NumArray(vector<int>& nums) {
        nums_.swap(nums);
        if(!nums_.empty())
            root_.reset(buildTree(0,nums_.size()-1));
    }
    
    void update(int index, int val) {
        updateTree(root_.get(),index,val);
    }
    
    int sumRange(int left, int right) {
        return sumRange(root_.get(),left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */