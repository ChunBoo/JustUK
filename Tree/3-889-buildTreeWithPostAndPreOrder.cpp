/**
 * @file 3-889-buildTreeWithPostAndPreOrder.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-22
 * 
 * @copyright Copyright (c) 2024
 * Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]
 */

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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        const int n=preorder.size();
        for(int i=0;i<n;++i)
            index[postorder[i]]=i;

        function<TreeNode *(int,int,int,int)> dfs=[&](int preLeft,int preRight,int postLeft,int postRight)-> TreeNode *{
            if(preLeft>preRight)
                return nullptr;
            
            int leftCnt=0;
            if(preLeft<preRight)
                leftCnt=index[preorder[preLeft+1]]-postLeft+1;
            return  new TreeNode(preorder[preLeft],
                        dfs(preLeft+1,preLeft+leftCnt,postLeft,postLeft+leftCnt-1),
                        dfs(preLeft+leftCnt+1,preRight,postLeft+leftCnt,postRight-1));
            // return root;
        };
        return dfs(0,n-1,0,n-1);
        

    }
private:
    int m_idx;
    map<int,int> index;
};