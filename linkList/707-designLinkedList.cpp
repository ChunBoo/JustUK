/***Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
 * 
 */

class MyLinkedList {
    private:
    struct Node{
        int val;
        Node* next;
        Node(int val,Node* next=nullptr):
         val(val),next(next){};
    };
    Node* tail_;
    Node* head_;
    int size_;
public:
    MyLinkedList():tail_{nullptr},head_{nullptr},size_(0) {

    }
    ~MyLinkedList()
    {
        Node* node=head_;
        while(node)
        {
            Node* cur=node;
            node=node->next;
            delete cur;
        }
        head_=nullptr;
        tail_=nullptr;
    }
    
    int get(int index) {
        if(index<0||index>=size_) return -1;
        auto node=head_;
        while(index--)
            node=node->next;
        return node->val;
    }
    
    void addAtHead(int val) {
        head_=new Node(val,head_);
        if(size_++==0)
            tail_=head_;
    }
    
    void addAtTail(int val) {
        auto node=new Node(val);
        if(size_++==0){
            head_=tail_=node;
        }
        else{
            tail_->next=node;
            tail_=tail_->next;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index<0||index>size_) return ;
        if(index==0) return addAtHead(val);
        if(index==size_) return addAtTail(val);
        Node dummy(0,head_);
        Node* prev=&dummy;
        while(index--) prev=prev->next;
        prev->next=new Node(val,prev->next);
        ++size_;
    }
    
    void deleteAtIndex(int index) {
        if(index<0||index>=size_) return;
        Node dummy(0,head_);
        Node* prev=&dummy;
        for(int i=0;i<index;++i)
            prev=prev->next;
        Node* nodeToDel=prev->next;
        prev->next=nodeToDel->next;
        if(index==0) head_=prev->next;
        if(index==size_-1) tail_=prev;
        delete nodeToDel;
        --size_;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */