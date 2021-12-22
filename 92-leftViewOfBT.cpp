//left view of a BT use BFS
#include"treeNode.h"
#include<vector>
#include<deque>


void getLeftViewOfBT(TreeNode* root,std::vector<int>& list)
{
    std::vector<int> ret{};
    if(!root)
        return ;
    
    std::deque<TreeNode*> d{};

    d.push_back(root);
    
    while(!d.empty())
    {
        // if(d.size()>1)
        //     list.push_back(d[1]->m_val);
        // else
            list.push_back(d[0]->m_val);
        int sz=d.size();
        for(int i=0;i<sz;++i)
        {
            TreeNode* curNode=d.front();
            d.pop_front();
            if(curNode->left)
                d.push_back(curNode->left);
            if(curNode->right)
                d.push_back(curNode->right);
        }
    }
}

int main()
{
    TreeNode* root=new TreeNode(4);
    TreeNode* left=new TreeNode(3);
    TreeNode* right=new TreeNode(8);

    // left->addLeftChild(2);
    root->left=left;
    root->addRightChild(5);
    // right->addLeftChild(7);
    right->addRightChild(9);
    root->right=right;
    std::vector<int> list{};
    getLeftViewOfBT(root,list);
    for(auto i:list)
        std::cout<<i<<'-';

    return 0;
}