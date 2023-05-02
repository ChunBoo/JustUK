from ListNode import ListNode
'''
我们可以设想假设设定了双指针 p 和 q 的话，当 q 指向末尾的 NULL，p 与 q 之间相隔的元素个数为 n 时，那么删除掉 p 的下一个指针就完成了要求。

设置虚拟节点 dummyHead 指向 head
设定双指针 p 和 q，初始都指向虚拟节点 dummyHead
移动 q，直到 p 与 q 之间相隔的元素个数为 n
同时移动 p 与 q，直到 q 指向的为 NULL
将 p 的下一个节点指向下下个节点

'''
def removeNthFromEnd(header,n):
    i=1
    p,q=header,header
    while(i<=n):
        i+=1
        if not p.next:
            return p.next
        else:
            p=p.next
    while p.next:
        p=p.next
        q=q.next
    q.next=q.next.next
    return header

first=ListNode(1)
second=ListNode(2)
third=ListNode(3)
four=ListNode(4)
five=ListNode(5)
first.setNext(second)
second.setNext(third)
third.setNext(four)
four.setNext(five)

res=removeNthFromEnd(first,2)
while(res):
    print(res.val,"->")
    res=res.next
