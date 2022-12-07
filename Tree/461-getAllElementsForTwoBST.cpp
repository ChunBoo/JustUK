#include<iostream>
#include<vector>

using VEC=std::vector<int>;


class TreeNode
{
    public:
        int val{};
        TreeNode* left{};
        TreeNode* right{};
        TreeNode(int v,TreeNode* l=nullptr,TreeNode* r=nullptr):val{v},left{l},right{r}{};
};

void inorder(TreeNode* r,VEC& list)
{
    if(!r)
        return;
    inorder(r->left,list);
    list.push_back(r->val);
    inorder(r->right,list);
}

VEC allElements(TreeNode* r1,TreeNode* r2)
{
    VEC ans{};
    VEC l1{},l2{};
    
    inorder(r1,l1);
    inorder(r2,l2);

    //merge values
    int n1=l1.size(),n2=l2.size();
    int i=0,j=0;
    while(i<n1 &&j<n2)
    {
        if(l1[i]<l2[j])
        {
            ans.push_back(l1[i]);
            i+=1;
        }
        else
        {
            ans.push_back(l2[j]);
            j+=1;
        }
    }
    if(i<n1)
    {
        for(auto &v:l1)
            ans.push_back(v);
    }
    if(j<n2)
    {
        for(auto &v:l2)
            ans.push_back(v);
    }
    return ans;
}

int main()
{
    TreeNode* r1=new TreeNode(2);
    TreeNode* l11=new TreeNode(1);
    TreeNode* r11=new TreeNode(3);

    r1->right=r11;
    r1->left=l11;

    TreeNode* r2=new TreeNode(5);
    TreeNode* l22=new TreeNode(4);
    TreeNode* r22=new TreeNode(6);
    r2->left=l22;
    r2->right=r22;

    VEC res=allElements(r1,r2);
    for(auto &v:res)
        std::cout<<v<<',';
}