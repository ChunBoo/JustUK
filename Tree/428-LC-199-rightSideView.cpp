#include<iostream>
#include<vector>
#include<queue>
using VEC=std::vector<int>;

class TreeNode
{
    private:
        int m_val{};
        TreeNode *m_left{nullptr};
        TreeNode *m_right{nullptr};
    public:
        TreeNode(int val,TreeNode* left=nullptr, TreeNode* right=nullptr):m_val{val},m_left{left},m_right{right}{}
        void addLeft(TreeNode* left){m_left=left;}
        void addRight(TreeNode* right){m_right=right;}
        TreeNode* getLeft() {return m_left;}
        TreeNode* getRight() {return m_right;}
        int getVal() const {return m_val;}
};

VEC rightSide(TreeNode* root)
{
    VEC ans{};
    if(!root)
        return ans;

    std::queue<TreeNode*> q{};
    q.push(root);
    while(!q.empty())
    {
        ans.push_back(q.back()->getVal());
        int n=q.size();
        for(int i=0;i<n;++i)
        {
            TreeNode* curNode=q.front();
            q.pop();

            if(curNode->getLeft())
                q.push(curNode->getLeft());
            if(curNode->getRight())
                q.push(curNode->getRight());

        }
    }
    return ans;
}

int main()
{
    VEC nums{1,2,3,4,5};
    TreeNode *root=new TreeNode(1);
    TreeNode *l1=new TreeNode(2);
    TreeNode *r1=new TreeNode(3);
    TreeNode *l2=new TreeNode(4);
    TreeNode *r2=new TreeNode(5);

    root->addLeft(l1);
    root->addRight(r1);
    l1->addLeft(l2);
    l1->addRight(r2);
    VEC res=rightSide(root);
    for(auto &v:res)
        std::cout<<v<<',';
}

