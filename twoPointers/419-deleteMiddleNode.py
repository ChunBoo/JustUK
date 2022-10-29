# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def deleteMiddle(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not head:
            return head
        if not head.next
            return head.next
        
        pre=None
        s=f=head
        while f and f.next:
            f=f.next.next
            pre=s
            s=s.next
            
        pre.next=s.next
        return head