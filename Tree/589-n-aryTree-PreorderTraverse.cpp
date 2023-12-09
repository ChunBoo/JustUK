/**
 * Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. 
Each group of children is separated by the null value (See examples)
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
            if(!root)
         return {};
        vector<int> ans_;
        dfs(root,ans_);
        return ans_;
    }
private:
    void dfs(Node* root,vector<int>& ans)
    {
        if(!root)
        return;
            ans.push_back(root->val);
        for(auto child:root->children)
        {
            dfs(child,ans);
        }
    

    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root)
            return {};
        stack<Node*> s;  //STACK IS FILO
        s.push(root);
        vector<int> ans;
        while(!s.empty())
        {
            Node* curr=s.top();
            s.pop();
            ans.push_back(curr->val);
            for(auto it=curr->children.rbegin();it!=curr->children.rend();++it)
            {
                s.push(*it);
            }
        }
        return ans;
    }
};