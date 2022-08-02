class LinkList:
    def __init__(self,val=None,next=None):
        self.val=val
        self.next=next
        

def isAscendingLinkList(head):
    if not head:
        return True
    data=[]
    
    while(head):
        data+=[head.val]
        head=head.next
        
    for i in range(1,len(data)-1):
        if data[i+1]<=data[i]:
            return False
    return True


head=LinkList(1)
first=LinkList(2)
second=LinkList(2)

head.next=first
first.next=second

print(isAscendingLinkList(head))