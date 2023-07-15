/**Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3

 * 
 * 
*/

namespace{
struct CacheNode{
    int key;
    int value;
    int freq;
    long tick;
    bool operator<(const CacheNode& rhs) const {
        if(freq<rhs.freq) return true;
        if(freq==rhs.freq) return tick<rhs.tick;
        return false;
    }
};
}

class LFUCache {
private:
    long tick_;
    int capacity_;
    unordered_map<int,CacheNode> m_;
    set<CacheNode> cache_;
    void touch(CacheNode& node){
        cache_.erase(node);
        ++node.freq;
        node.tick=++tick_;
        cache_.insert(node);
    }
public:
    LFUCache(int capacity):capacity_(capacity),tick_(0) {}
    
    int get(int key) {
        auto it=m_.find(key);
        if(it==m_.cend()) return -1;
        int value=it->second.value;
        touch(it->second);
        return value;
    }
    
    void put(int key, int value) {
        if(capacity_==0) return;
        auto it=m_.find(key);
        if(it!=m_.cend()){
            it->second.value=value;
            touch(it->second);
            return ;
        }
        if(m_.size()==capacity_){
            const CacheNode& node=*cache_.cbegin();
            m_.erase(node.key);
            cache_.erase(node);
        }
        CacheNode node{key,value,1,++tick_};
        m_[node.key]=node;
        cache_.insert(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


struct CacheNode{
    int key;
    int value;
    int freq;
    list<int>::const_iterator it;  //pointer to the node in the list
};


class LFUCache {
private:
    int capacity_;
    int min_freq_;
    //key--->CacheNode
    unordered_map<int,CacheNode> n_;
    //freq-->keys with freq
    unordered_map<int,list<int>> l_;
    void touch(CacheNode& node){
        //s1:update the freq
        const int prev_freq=node.freq;
        const int freq=++(node.freq);

        //s2:remove the entry from old freq_list
        l_[prev_freq].erase(node.it);
        //s3
        if(l_[prev_freq].empty()&&prev_freq==min_freq_){
            //del the lsit
            l_.erase(prev_freq);
            ++min_freq_;
        }
        //s4, insert the key into the front of the new freq list
        l_[freq].push_front(node.key);
        //s5: update the pointer
        node.it=l_[freq].cbegin();
    }
public:
    LFUCache(int capacity):capacity_(capacity),min_freq_(0){}
    
    int get(int key) {
        auto it=n_.find(key);
        if(it==n_.cend()) return -1;
        touch(it->second);
        return it->second.value;
    }
    
    void put(int key, int value) {
        if(capacity_==0) return;
        auto it=n_.find(key);
        if(it!=n_.cend()){
            it->second.value=value;
            touch(it->second);
            return ;
        }
        if(n_.size()==capacity_){
            //no capacity, remove one entry that has lowest freq or least recently used if there are mul one
            //s1:remove the element from m_freq_list
            const int key_to_evict=l_[min_freq_].back();
            l_[min_freq_].pop_back();
            //s2:remove the key from cache
            n_.erase(key_to_evict);
        }
        const int freq=1;
        min_freq_=freq;
        //add the key to the freq list
        l_[freq].push_front(key);
        //create new node
        n_[key]={key,value,freq,l_[freq].cbegin()};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */