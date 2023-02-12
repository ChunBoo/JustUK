#include<iostream>
#include<queue>

using std::cout;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int v,TreeNode* l=nullptr, TreeNode* r=nullptr):val{v},left{l},right{r}{};
};
using Q=std::queue<std::pair<const TreeNode*,int>>;
bool hasPathSum(const TreeNode* root,int target)
{
    if(!root)
        return false;

    Q q{};
    q.push(std::make_pair(root,0));
    while(!q.empty())
    {
        std::pair<const TreeNode*,int> top=q.front();
        q.pop();
        const TreeNode* curNode=top.first;
        int s=top.second;
        int curVal=s+curNode->val;
        if((curVal==target)&&(!curNode->left)&&(!curNode->right))
            return true;
        if(curNode->left)
            q.push(std::make_pair(curNode->left,curVal));
        if(curNode->right)
            q.push(std::make_pair(curNode->right,curVal));
    }
    return false;
    
}

int main()
{
    TreeNode* root=new TreeNode(7);
    TreeNode* one=new TreeNode(1);
    TreeNode* two=new TreeNode(2);
    TreeNode* three=new TreeNode(2);

    root->left=one;
    one->left=two;
    one->right=three;
    cout<<hasPathSum(root,11);
}