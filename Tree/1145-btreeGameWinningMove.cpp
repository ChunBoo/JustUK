/**
 * Definition for a binary tree node.
 */
 #include<iostream>
 #include<cmath>
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        nodes(root,x);
        int p=n-m_l-m_r-1;
        return std::max(p, std::max(m_l,m_r))>n/2;
    }
    private:
        int m_l,m_r;
        int nodes(TreeNode* root,int x)
        {
            if(!root)
                return 0;
            int l=nodes(root->left,x);
            int r=nodes(root->right,x);

            if(root->val==x)
            {
                m_r=r;
                m_l=l;
            }
            return l+r+1;
        }
};


int main()
{
    using std::cout;
    TreeNode *root=new TreeNode(1);
    TreeNode *two=new TreeNode(2);
    TreeNode *three=new TreeNode(3);
    TreeNode *four=new TreeNode(4);
    TreeNode *five=new TreeNode(5);
    TreeNode *six=new TreeNode(6);
    TreeNode *seven=new TreeNode(7);

    root->left=two;
    root->right=three;

    two->left=four;
    two->right=five;
    three->left=six;
    four->left=seven;
    cout<<Solution().btreeGameWinningMove(root,7,3);

}