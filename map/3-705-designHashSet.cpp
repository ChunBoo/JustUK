
/***
 * Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
 

Example 1:

Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)
 

Constraints:

0 <= key <= 106
At most 104 calls will be made to add, remove, and contains.
 * 
*/
// class MyHashSet {
// public:
//     MyHashSet() {

//     }
    
//     void add(int key) {
//         auto iter=std::find(begin(vec_),end(vec_),key);
//         if(iter==end(vec_))
//             vec_.push_back(key);
//     }
    
//     void remove(int key) {
//         auto iter=std::find(begin(vec_),end(vec_),key);
//         if(iter!=end(vec_))
//         {
//             vec_.erase(iter);
//         }
//     }
    
//     bool contains(int key) {
//         return std::find(begin(vec_),end(vec_),key)!=end(vec_);
//     }
// private:
//     vector<int> vec_;
// };


class MyHashSet {
public:
    MyHashSet():data_(base) {

    }
    
    void add(int key) {
        int h=hash(key);
        for(auto it=data_[h].begin();it!=data_[h].end();it++)
        {
            if((*it)==key)
                return;
        }
        data_[h].push_back(key);
    }
    
    void remove(int key) {
        int h=hash(key);
        for(auto it=data_[h].begin();it!=data_[h].end();it++)
        {
            if((*it)==key)
            {
                data_[h].erase(it);
                return ;
            }
        }
    }
    
    bool contains(int key) {
        int h=hash(key);
        for(auto it=data_[h].begin();it!=data_[h].end();it++){
            if((*it)==key)
                return true;
        }
        return false;
    }
private:
    vector<list<int>> data_;
    static const int base = 769;
    static int hash(int key){
        return key%base;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */