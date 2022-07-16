//reference link:https://stackoverflow.com/questions/33132436/equivalent-python-nested-dictionary-in-c
#include<queue>
#include"treeNode.h"
#include<iostream>
#include<map>
#include<string>
using DT=std::map<int,std::pair<std::map<std::string,int>>>;// this should be implemented by https://stackoverflow.com/questions/33132436/equivalent-python-nested-dictionary-in-c

bool isCousin_BFS(const TreeNode* root,int x,int y)
{
    if(!root)
        return false;


}