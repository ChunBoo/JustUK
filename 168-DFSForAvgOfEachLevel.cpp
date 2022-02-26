#include<iostream>
#include"treeNode.h"
#include<vector>
#include<map>

using PAIR=std::pair<int,int>;

void dfs(TreeNode* root, int level ,std::map<int,std::vector<int>>& list)
{
    if(!root)
        return;

    list[level].push_back(root->m_val);
    if(root->left)
        dfs(root->left,level+1,list);
    if(root->right)
        dfs(root->right,level+1,list);
}

std::vector<float> avgOfEachLevel(TreeNode* root)
{
    std::vector<float> ans;
    if(!root)
        return ans;
    
    std::map<int,std::vector<int>> map;
    
    dfs(root,0,map);
    for(auto i:map)
    {
        int sum=0;
        std::vector<int> tempList=i.second;
        int sz=tempList.size();
        for(auto v:tempList)
            sum+=v;
        ans.push_back(float(sum)/sz);
    }
    return ans;    
}


int main()
{
    TreeNode* r1=new TreeNode(2);
    TreeNode* l1=new TreeNode(4);
    TreeNode* r11=new TreeNode(4);
    r1->left=l1;
    r1->right=r11;
    
    std::vector<float> res=avgOfEachLevel(r1);
    for(auto i:res)
        std::cout<<i<<'\n';

    return 0;
}