/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        const int n=postorder.size();
        m_postIdx=n-1;
        //create the index map
        for(int i=0;i<n;++i)
            index[inorder[i]]=i;
        return buildTree(0,n-1,inorder,postorder);
    }
private:
    int m_postIdx;
    map<int,int> index;
    TreeNode* buildTree(int inLeft,int inRight,const vector<int>& inorder,const vector<int>& postorder){
        if(inLeft>inRight)
            return nullptr;
        
        int rootVal=postorder[m_postIdx];
        TreeNode* root=new TreeNode(rootVal);

        int idx=index[rootVal];
        m_postIdx-=1;
        //create the right subtree   //can not create the left tree first
        root->right=buildTree(idx+1,inRight,inorder,postorder);

        //create the left subtree
        root->left=buildTree(inLeft,idx-1,inorder,postorder);

        return root;
    }
};