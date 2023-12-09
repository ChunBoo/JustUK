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
private:
    void dfs(Node* root,vector<int>& ans)
    {
        if(!root)
        return;
        for(auto child:root->children)
        {
            dfs(child,ans);
        }
        ans.push_back(root->val);

    }
public:
    vector<int> postorder(Node* root) {
        if(!root)
         return {};
        vector<int> ans_;
        dfs(root,ans_);
        return ans_;
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
    vector<int> postorder(Node* root) {
      if(!root)
        return {};
      stack<Node*> s;
      s.push(root);
      vector<int> ans;
      while(!s.empty())
      {
          const Node* curr=s.top();
          s.pop();
          ans.push_back(curr->val);
        //   for(auto it=curr->children.rbegin();it!=curr->children.rend();++it)
          for(const auto child:curr->children)
          {
              s.push(child);
          }
      }
      return {ans.rbegin(),ans.rend()};
    }
};