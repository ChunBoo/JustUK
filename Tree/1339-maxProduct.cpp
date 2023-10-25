/**
 * Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.
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
    int maxProduct(TreeNode* root) {
        const int kMod=1e9+7;
        long s=0,ans=0;
        function<int(TreeNode*)> sum=[&](TreeNode* r){
            if(!r) return 0;
            int sl=sum(r->left);
            int sr=sum(r->right);
            if(s)
              ans=max({ans,(s-sl)*sl,(s-sr)*sr});
            return r->val+sl+sr;
        };
        s=sum(root);
        sum(root);
        return ans%kMod;
    }
};