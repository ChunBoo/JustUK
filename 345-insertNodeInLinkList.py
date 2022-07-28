class Node:
    def __init__(self,val=None,next=None):
        self.val=val
        self.next=next
        
        


def insert(head,val,pos):
    if not head:
        return Node(val)
    newNode=Node(val)
    dummy=Node(0,head)
    preNode=dummy
    
    for _ in range(pos):
        preNode=head
        head=head.next

    preNode.next=newNode
    newNode.next=head
    return dummy.next

fNode=Node(1)
sNode=Node(2)

