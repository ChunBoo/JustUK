#include<iostream>
#include<vector>
using namespace std;
class MinHeap{
    public:
        MinHeap();
        MinHeap(const vector<int>& data);
        int peek() const;
        int pop();
        void push(int key);
        int size() const;

    private:
        void heapifyUp(int index);
        void heapifyDown(int index);
        vector<int> data_;
};


void MinHeap::push(int key){
    data_.push_back(key);  //add the element to the end of the array, O(1)
    heapifyUp(data_.size()-1);  //θ(logn)
}

void MinHeap::heapifyUp(int index){
    if(index==0) return; //stop at root
    int parent=(index-1)/2;  
    if(data_[index]>=data_[parent]) return; //stop if greater or equal to parent
    swap(data_[index],data_[parent]);
    heapifyUp(parent);  //continue to heapifyup on parent
}
//extract the min elemnt
int MinHeap::pop(){
    swap(data_.back(),data_[0]);//swap the min element with the last one,O(1)
    int min_ele=data_.back();  //Get the min element, O(1)
    data_.pop_back();           //Evict the min element, O(1)
    heapifyDown(0);             //Maintain heap property θ(logn)
    return min_ele;
}

void MinHeap::heapifyDown(int index){
    int smallest=index;
    //get the min child
    for(int c:{index*2+1,index*2+2})
        if(c<data_.size()&&data_[c]<data_[smallest])
            smallest=c;
    if(smallest==index) return;
    //swap with min child
    swap(data_[index],data_[smallest]);
    heapifyDown(smallest); //continue heapifyDown on min child
}

int main() {
  vector<int> data{5,1,3,5,3,4,3,7};
  MinHeap heap;
  for (int x : data)
    heap.push(x);
  vector<int> output;
  while (heap.size())
    output.push_back(heap.pop());
  assert(output == vector<int>({1,3,3,3,4,5,5,7}));
}