/**
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

/*
Binary format
serialized size: 4*n bytes, n is the number of nodes in the BST.
Time complexity: O(n)
Space complexity: O(n)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class 
class Codec {
public:
 
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serialize(root, s);
        return s;
    }
 
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {        
        int pos = 0;
        return deserialize(data, pos, INT_MIN, INT_MAX);
    }
private:
    void serialize(TreeNode* root, string& s) {
        if (!root) return;    
        s.append(reinterpret_cast<const char*>(&root->val), sizeof(root->val));
        serialize(root->left, s);
        serialize(root->right, s);
    }
    
    TreeNode* deserialize(const string& s, int& pos, int curMin, int curMax) {
        if (pos >= s.size()) return nullptr;
        int val = *reinterpret_cast<const int*>(s.data() + pos);
        if (val < curMin || val > curMax) return nullptr;
        pos += sizeof(val);
        TreeNode* root = new TreeNode(val);
        root->left = deserialize(s, pos, curMin, val);
        root->right = deserialize(s, pos, val, curMax);
        return root;
    }
};