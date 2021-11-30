//合并K个单向有序链表
//类似二分查找法，但是时间复杂度是O(K*N)

#include<iostream>
#include<vector>
#include "linkNode.h"
using std::vector;
/**
 * Definition for singly-linked list.
 * struct LinkNode {
 *     int m_val;
 *     LinkNode *next;
 *     LinkNode() : m_val(0), next(nullptr) {}
 *     LinkNode(int x) : m_val(x), next(nullptr) {}
 *     LinkNode(int x, LinkNode *next) : m_val(x), next(next) {}
 * };
 */
class Solution {
public:
    LinkNode* mergeKLists(vector<LinkNode*>& lists) {
        if(lists.size()<=0) return nullptr;
        return merge(lists,0,lists.size()-1);
    }
private:
    LinkNode* merge(vector<LinkNode*>& lists,int left,int right){
        if(left>right){
            return nullptr;
        }
        if(left==right){
            return lists[left];
        }
        int mid=(left+right)/2;
        return mergeLists(merge(lists,left,mid),merge(lists,mid+1,right));
    }

};

LinkNode* merge(std::vector<LinkNode*>& lists,int l,int r)
{
    if(l==r) return lists[l];
    if(l>r) return nullptr;
    int mid=(l+r)/2;
    return mergeLists(merge(lists,l,mid),merge(lists,mid+1,r));
}


LinkNode* mergeKListsmergeKthSortedList(std::vector<LinkNode*>& headLists)
{

    return merge(headLists,0,headLists.size()-1);
}


int main()
{
    std::vector<LinkNode*> headList;
    LinkNode* head1=new LinkNode(-1);
    LinkNode* head2=new LinkNode(-1);
    LinkNode* head3=new LinkNode(-1);
    LinkNode* head4=new LinkNode(-1);
    LinkNode* p1=head1;
    LinkNode* p2=head2;
    LinkNode* p3=head3;
    LinkNode* p4=head4;
    for(int i=0;i<20;++i)
    {
        if(i<5)
        {
            p1->next= new LinkNode(i);
            p1=p1->next;
        }
        else if(i>=5 && i<10)
        {
            p2->next=new LinkNode(i);
            p2=p2->next;
        }
        else if(i>=10&&i<15)
        {
            p3->next=new LinkNode(i);
            p3=p3->next;
        }
        else
        {
            p4->next=new LinkNode(i);
            p4=p4->next;
        }
            
    }
    headList.push_back(head1);
    headList.push_back(head2);
    headList.push_back(head3);
    headList.push_back(head4);

    head1->printNode();
    head2->printNode();
    head3->printNode();
    head4->printNode();
    std::cout<<"after mergin:\n";
    Solution s;
    LinkNode* H=mergeKListsmergeKthSortedList(headList);
    H->printNode();
    return 0;
}

