/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

 #include<vector>
 #include<algorithm>
 #include<iostream>

 using namespace std;

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        ListNode* myHead=new ListNode(-1);;
        ListNode* curNode=head;
        dummy->next=myHead;
        while(curNode)
        {
            if(std::find(nums.begin(),nums.end(),curNode->val)==nums.end()){
                myHead->next=curNode;
                myHead=curNode;
            }
            curNode=curNode->next;
        }
        myHead->next=nullptr;
        return dummy->next->next;
    }
};