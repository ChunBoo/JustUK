#include<iostream>
#include<queue>
#include<vector>
struct BSTTreeNodes
{
    int mValue;
    BSTTreeNodes *left=nullptr;
    BSTTreeNodes *right=nullptr;
    BSTTreeNodes(int val):mValue{val}{}   
};



int countOfDFS(BSTTreeNodes *root)
{
    if(!root)
        return 0;
    return 1+countOfDFS(root->left)+countOfDFS(root->right);
}

int countOfBFS(BSTTreeNodes *root)
{
    if(!root)
        return 0;
    std::queue<BSTTreeNodes*> q;
    int ans=0;
    q.push(root);
    while(!q.empty())
    {
        BSTTreeNodes* curNode=q.front();
        q.pop();
        ans+=1;
        if(curNode->left)
            q.push(curNode->left);
        if(curNode->right)
            q.push(curNode->right);
    }
    return ans;
}

BSTTreeNodes* createTree(std::vector<int>& vals)
{
    if(vals.empty())
        return nullptr;
    BSTTreeNodes* root= new BSTTreeNodes(vals[0]);

    int sz=vals.size();
    for(int i=1;i<sz;++i)
    {
        BSTTreeNodes *tempNode=new BSTTreeNodes(vals[i]);
        if(i%2)  //left child
            root->left=tempNode;
        else
            root->right=tempNode;
    }
}