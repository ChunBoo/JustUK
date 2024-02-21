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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        const int n=preorder.size();
        if(n==1)
            return new TreeNode(preorder[0]);
        
        TreeNode* root=new TreeNode(preorder[0]);
        stack<TreeNode*> st;

        st.push(root);
        int inorderIndex=0;
        for(int i=1;i<n;++i){
            int preorderVal=preorder[i];
            TreeNode* node=st.top();
            if(node->val!=inorder[inorderIndex]){
                node->left=new TreeNode(preorderVal);
                st.push(node->left);
            }
            else{
                while(!st.empty()&&st.top()->val==inorder[inorderIndex]){
                    node=st.top();
                    st.pop();
                    ++inorderIndex;
                }
                node->right=new TreeNode(preorderVal);
                st.push(node->right);
            }
        }
        return root;
    }
};


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        const int preLen=preorder.size();
        const int inLen=inorder.size();
        if(preLen!=inLen)
            return nullptr;
  
        for(int i=0;i<inLen;++i)
            index[inorder[i]]=i;

        // function<TreeNode*(int,int,int,int)> myBuildTree=[&](int preLeft,int preRight,int inLeft,int inRight ){
        //     if(preLeft>preRight)
        //         return nullptr;
        //     int preRoot=preLeft;
        //     int inRoot=index[preorder[preRoot]];
        //     TreeNode* root=new TreeNode(preorder[preRoot]);
        //     //Get the count of left tree
        //     int sizeLeftTree=inRoot-inLeft;
        //     //create the left subtree
        //     root->left=myBuildTree(preLeft+1,preLeft+sizeLeftTree,inLeft,inRoot-1);
        //     root->right=myBuildTree(preLeft+sizeLeftTree+1,preRight,inRoot+1,inRight);
        //     return root;
        // };
        return myBuildTree(preorder,inorder, 0,preLen-1,0,preLen-1);
    }
    private:
          map<int,int> index;
         TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preLeft,int preRight,int inLeft,int inRight ){
            if(preLeft>preRight)
                return nullptr;
            int preRoot=preLeft;
            int inRoot=index[preorder[preRoot]];
            TreeNode* root=new TreeNode(preorder[preRoot]);
            //Get the count of left tree
            int sizeLeftTree=inRoot-inLeft;
            //create the left subtree
            root->left=myBuildTree(preorder,inorder,preLeft+1,preLeft+sizeLeftTree,inLeft,inRoot-1);
            root->right=myBuildTree(preorder,inorder,preLeft+sizeLeftTree+1,preRight,inRoot+1,inRight);
            return root;
        };
};