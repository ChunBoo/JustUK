/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution { // brute-force
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode dummy(0);
      ListNode *tail = &dummy;

      auto comp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
      priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> q(comp);

      for (ListNode *list : lists)
        if (list)
          q.push(list);

      while (!q.empty()) {
        tail->next = q.top();
        q.pop();
        tail = tail->next;
        if (tail->next)
          q.push(tail->next);
      }
      return dummy.next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists,0,lists.size()-1);
    }
private:
    ListNode* merge(vector<ListNode*>& lists,int l,int r){
        if(l>r) return nullptr;
        if(l==r) return lists[l];
        if(l+1==r) return mergeTwoLists(lists[l],lists[r]);
        int m=l+(r-l)/2;
        auto l1=merge(lists,l,m);
        auto l2=merge(lists,m+1,r);
        return mergeTwoLists(l1,l2);
    }
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* tail=&dummy;
        while(l1&&l2){
          if (l1->val > l2->val)
            std::swap(l1, l2);
          tail->next = l1;
          l1 = l1->next;
          tail = tail->next;
        }
        if(l1) tail->next=l1;
        if(l2) tail->next=l2;
        return dummy.next;
    }
};

int main() {

  ListNode *r1 = new ListNode(1);
  ListNode *l12 = new ListNode(2);
  ListNode *l13 = new ListNode(3);
  r1->next = l12;
  l12->next = l13;
  ListNode *r2 = new ListNode(0);

  ListNode *l21 = new ListNode(4);
  ListNode *l22 = new ListNode(10);
  r2->next = l21;
  l21->next = l22;
  ListNode *r3 = new ListNode(-1);

  ListNode *l31 = new ListNode(21);
  ListNode *l32 = new ListNode(8);
  r3->next = l31;
  l31->next = l32;
  vector<ListNode *> nodes{r1, r2, r3};
  ListNode *res = Solution2().mergeKLists(nodes);
  while (res) {
    cout << res->val << ',';
    res = res->next;
  }
}