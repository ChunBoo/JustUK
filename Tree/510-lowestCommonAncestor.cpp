#include "../treeNode.h"
#include<set>
#include<map>
#include<iostream>

using std::cout;
using SET=std::set<const TreeNode*>;
using MAP=std::map<const TreeNode*,const TreeNode*>;

const TreeNode* f(const TreeNode* root,const TreeNode* p, const TreeNode* q)
{
    if(!root)
        return nullptr;
    if((p->m_val<root->m_val) && (q->m_val<root->m_val))
    {
        return f(root->left,p,q);
    }
    else if((p->m_val>root->m_val) && (q->m_val<root->m_val))
    {
        return f(root->right,p,q);
    }
    else
        return root;
}
const TreeNode* lowestCommonA(const TreeNode* root,const TreeNode* p, const TreeNode* q)
{
    if(!root)
        return nullptr;
    return f(root,p,q);
}

const TreeNode* lowestCommonAn(const TreeNode* root,const TreeNode* p, const TreeNode* q )  //iterator method
{
    if(!root)
        return nullptr;

    while(root)
    {
        if((p->m_val<root->m_val) && (q->m_val<root->m_val))
            root=root->left;
        else if ((p->m_val>root->m_val) && (q->m_val<root->m_val))
            root=root->right;
        else
            break;
    }
    return root;
}

void dfoo(const TreeNode* root, const TreeNode* par,MAP& m)
{
    if(!root)
        return;
    dfoo(root->left,root,m);
    dfoo(root->right,root,m);
    m[root]=par;
}
const TreeNode* lowestCommonAnMap(const TreeNode* root,const TreeNode* p, const TreeNode* q )  //map
{
    MAP m{};
    SET seen{};
    dfoo(root,nullptr,m);

    while(p)
    {
        seen.insert(p);
        p=m[p];
    }
    while(q)
    {
        if(seen.find(q)!=seen.end())
            return q;
        q=m[q];
    }
    return nullptr;
}


int main()
{
    TreeNode* seven=new TreeNode(7);
    TreeNode* eight=new TreeNode(8);
    TreeNode* five=new TreeNode(5);
    TreeNode* four=new TreeNode(4);
    TreeNode* two=new TreeNode(2);
    TreeNode* one=new TreeNode(1);
    TreeNode* three=new TreeNode(3);

    seven->left=five;
    five->left=four;
    four->left=two;
    two->left=one;
    two->right=three;
    seven->right=eight;

    cout<<lowestCommonA(seven,one,three)->m_val;
    cout<<lowestCommonAn(seven,one,three)->m_val;
    cout<<lowestCommonAnMap(seven,one,three)->m_val;
}
