//using std::set() to get the root of N-ary tree
#include"NARYTree.h"
#include<set>
#include<iostream>
#include<vector>

NNode* getRoot(const std::vector<NNode*>& nodes)
{
    if(nodes.empty())
        return nullptr;
    std::set<NNode*> nodeSet;
    for(auto node:nodes)
    {
        for(auto child:node->m_children)
        {
            nodeSet.insert(child);
        }
    }
    for(auto n:nodes)
    {
        auto search=nodeSet.find(n);
        if(search==nodeSet.end())
        {
            return n;
        }
    }
    return nullptr;
}

int main()
{
    NNode* root=new NNode(888);
    NNode* c1=new NNode(1);
    NNode* c2=new NNode(2);
    NNode* c3=new NNode(3);
    // root->addChild(c1);
    // root->addChild(c2);
    // root->addChild(c3);
    c3->addChild(c1);
    c3->addChild(c2);
    c3->addChild(root);
    std::vector<NNode*> nodes{root,c1,c2,c3};
    NNode* foundRoot=getRoot(nodes);
    if(foundRoot)
        std::cout<<foundRoot->m_val<<'\n';

    return 0;    
}