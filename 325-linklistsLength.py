
#recursion method to get the length of single link list
class LinkNode:
    def __init__(self,val,next=None) -> None:
        self.m_val=val
        self.next=next

def lenLinkList(head):
    # if not head:
    #     return 0
    
    return 1+lenLinkList(head.next) if head else 0


def lenLinkListIterator(head):
    ans=0
    p=head
    while(p):
        ans+=1
        p=p.next
    return ans
        
header=LinkNode(0)
first=LinkNode(1)
second=LinkNode(2)
third=LinkNode(3)
fourth=LinkNode(4)

header.next=first
first.next=second
second.next=third
third.next=fourth

print(lenLinkListIterator(header))