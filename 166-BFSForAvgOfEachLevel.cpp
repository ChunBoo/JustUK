//given a BT, calculate each levels average

#include<iostream>
#include"treeNode.h"
#include<deque>
#include<vector>

std::vector<float> averageOfEachLevel(TreeNode* root)
{
    std::vector<float> ans;
    if(!root)
        return ans;

   
    std::deque<TreeNode*> q;
    q.push_back(root);
    while(!q.empty())
    { 
        int sum=0;
        int sz=q.size();
        for(int i=0;i<sz;++i)
        {
            TreeNode* curNode=q.front();
            q.pop_front();
            sum+=curNode->m_val;
            if(curNode->left)
                q.push_back(curNode->left);
            if(curNode->right)
                q.push_back(curNode->right);
        }
        ans.push_back((sum)/sz);
    }
    return ans;
}

int main()
{
    TreeNode* r1=new TreeNode(2);
    TreeNode* l1=new TreeNode(3);
    TreeNode* r11=new TreeNode(4);
    r1->left=l1;
    r1->right=r11;
    
    std::vector<float> res=averageOfEachLevel(r1);
    for(auto i:res)
        std::cout<<i<<'\n';

    return 0;
}