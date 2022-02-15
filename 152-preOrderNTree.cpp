//n-Tree pre

#include<iostream>
#include<vector>
#include<stack>
struct NTree
{
    int m_val;
    NTree* root;
    std::vector<NTree*> children;
    NTree(int val):m_val{val},children{}{}
    void addChild(NTree* node){children.push_back(node);}
};

void preSeq(NTree* root,std::vector<NTree*>& res)
{
    
    if(!root)
        return ;

    res.push_back(root);

    for(auto child:root->children)
    {
        res.push_back(child);
    }  
}

int main()
{
    NTree* root=new NTree(2);
    NTree* c1=new NTree(3);
    NTree* c2=new NTree(4);
    NTree* c3=new NTree(5);
    NTree* c4=new NTree(6);
    NTree* r1=new NTree(7);
    NTree* r2=new NTree(8);
   
    c1->addChild(c2);
    c1->addChild(c3);
    c1->addChild(c4); 
    root->addChild(c1);
    root->addChild(r1);
    root->addChild(r2);
    std::vector<NTree*> res{};
    preSeq(root,res);
    if(!res.empty())
    {
        for(auto node:res)
        {
            std::cout<<node->m_val<<"--";
        }
    }
    return 0;
}




