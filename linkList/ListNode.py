class ListNode(object):
    def __init__(self,val,next=None):
        self.val=val
        self.next=next
    
    def setNext(self,next):
        self.next=next;