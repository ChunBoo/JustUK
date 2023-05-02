
from ListNode import ListNode

def isPalindrome(header):
    slow,fast=header,header
    prev=None
    while fast:  #found the middle node
        slow=slow.next
        if fast.next:
            fast=fast.next.next
        else:
            fast=fast.next
    # reverse the half
    while slow:
        tmp=slow.next
        slow.next=prev
        prev=slow
        slow=tmp
    
    while prev and header:
        if prev.val!=header.val:
            return False
        header=header.next
        prev=prev.next
        
    return True

first=ListNode(1)
second=ListNode(2)
third=ListNode(3)
four=ListNode(4)
five=ListNode(1)
first.setNext(second)
second.setNext(third)
third.setNext(four)
four.setNext(five)

print(isPalindrome(first))
        
        