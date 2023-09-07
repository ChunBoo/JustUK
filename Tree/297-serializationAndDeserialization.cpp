/**
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

1
2
3
4
5
    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

/**
 * Definition for a binary tree node.
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    ostringstream out;
    serialize(root, out);
    return out.str();
  }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }


private:
    void serialize(TreeNode* root, ostringstream& out){
        if(!root){
            out<<"# ";
            return;
        }
        out<<root->val<<" ";
        serialize(root->left,out);
        serialize(root->right,out);
        return;
    }
    TreeNode* deserialize(istringstream& in){
        string val;
        in>>val;
        if(val=="#") return nullptr;
        TreeNode* root=new TreeNode(stoi(val));
        root->left=deserialize(in);
        root->right=deserialize(in);
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec2 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    enum STATUS{
        ROOT_NULL=0x0,
        ROOT=0x1,
        LEFT=0x2,
        RIGHT=0x4
    };
    void serialize(TreeNode* root, ostringstream& out){
        char status=0;
        if(root) status|=ROOT;
        if(root&&root->left) status|=LEFT;
        if(root&&root->right) status|=RIGHT;
        out.write(&status,sizeof(char));
        if(!root) return;
        out.write(reinterpret_cast<char*>(&(root->val)),sizeof(root->val));
        if(root->left) serialize(root->left,out);
        if(root->right) serialize(root->right,out);
    }

    TreeNode* deserialize(istringstream& in){
        char status;
        in.read(&status,sizeof(char));
        if (!(status & ROOT))
          return nullptr;
        auto root=new TreeNode(0);
        in.read(reinterpret_cast<char*>(&root->val),sizeof(root->val));
        root->left=(status&LEFT)?deserialize(in):nullptr;
        root->right=(status&RIGHT)?deserialize(in):nullptr;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
  Codec2 ser; //, deser;
  TreeNode *root = new TreeNode(1);
  TreeNode *two = new TreeNode(2);
  TreeNode *three = new TreeNode(3);
  TreeNode *four = new TreeNode(4);
  TreeNode *five = new TreeNode(5);

  root->left = two;
  root->right = three;
  three->left = four;
  three->right = five;
  // ostreamstring out;
  //   string data{"1 2 # # 3 4 # # 5 # # "};
  cout << ser.serialize(root) << '\n';
  //   cout << deser.deserialize(data)->val;
}