//build a bst from a sorted list

#include<iostream>
#include<vector>

#include"treeNode.h"

TreeNode* buildBSTFromSortedList(std::vector<int>& nums)
{
    if(nums.empty())
        return nullptr;

    int mid=nums.size()/2;
    int tsize=nums.size();
    TreeNode* root=new TreeNode(nums[mid]);
    std::vector<int> leftPart{};
    std::vector<int> rightPart{};
    for(int i=0;i<mid;++i)
    {
        leftPart.push_back(nums[i]);
    }
    for(int i=mid;i<nums.size();++i)
    {
        rightPart.push_back(nums[i]);
    }
    root->left=buildBSTFromSortedList(leftPart);
    root->right=buildBSTFromSortedList(rightPart);
    return root;
}


int main()
{
    std::vector<int> nums{1,2,3,4,5,6};
    TreeNode* root=buildBSTFromSortedList(nums);
    root->printTreeInOrder(root);
    std::cout<<"\npreOrder:\n";
    root->printTreeNodePreOrder(root);
    return 0;
}