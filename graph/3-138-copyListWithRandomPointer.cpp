/**
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (!head) return head;
 
    unordered_map<Node*, Node*> m;    
    Node* cur = m[head] = new Node(head->val);
    Node* ans = cur;
 
    while (head) {
      if (head->random) {
        auto it = m.find(head->random);
        if (it == end(m))
          it = m.emplace(head->random, new Node(head->random->val)).first;
        cur->random = it->second;
      }
 
      if (head->next) {
        auto it = m.find(head->next);
        if (it == end(m))
          it = m.emplace(head->next, new Node(head->next->val)).first;        
        cur->next = it->second;
      }
 
      head = head->next;
      cur = cur->next;
    }
    
    return ans;
  }
};