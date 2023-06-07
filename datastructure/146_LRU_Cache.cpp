#include<list>
#include<unordered_map>
#include<iostream>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity=capacity;
    }
    
    int get(int key) {
        const auto it=m_map.find(key);
        if(it==m_map.cend())
        {
            cout<<"\n Error: can not find the value of "<<key<<'\n';
            return -1;
        }
        m_cache.splice(m_cache.begin(),m_cache,it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        const auto it=m_map.find(key);
        if(it!=m_map.cend())
        {
            it->second->second=value;
            m_cache.splice(m_cache.begin(),m_cache,it->second);
            return;
        }
        if((int)(m_cache.size())==m_capacity)
        {
            auto &node=m_cache.back();
            m_map.erase(node.first);
            m_cache.pop_back();
        }
        m_cache.emplace_front(key,value);
        m_map[key]=m_cache.begin();
    }
    private:
        int m_capacity;
        list<pair<int,int>> m_cache;
        unordered_map<int, list<pair<int,int>>::iterator> m_map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 int main()
 {
     int key=1,value=1;
     LRUCache* obj = new LRUCache(2);
    //  int param_1 = obj->get(key);
     obj->put(key,value);
     cout<<obj->get(key);
     key=2,value=2;
     obj->put(key,value);
     cout<<obj->get(2);

 }