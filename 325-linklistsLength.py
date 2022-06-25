


def lenLinkList(head):
    if not head:
        return 0
    
    return 1+lenLinkList(head.next) 

