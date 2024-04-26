/**
 * Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length.  Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id
Example 1:

Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation: 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5
Constraints:

1 <= length <= 50000
At most 50000 calls will be made to set, snap, and get.
0 <= index < length
0 <= snap_id < (the total number of times we call snap())
0 <= val <= 10^9
Solution: map + upper_bound
Use a vector to store maps, one map per element.
The map stores {snap_id -> val}, use upper_bound to find the first version > snap_id and use previous version’s value.

Time complexity:
Set: O(log|snap_id|)
Get: O(log|snap_id|)
Snap: O(1)
Space complexity: O(length + set_calls)
*/
class SnapshotArray {
public:
  SnapshotArray(int length): id_(0), vals_(length) {}
 
  void set(int index, int val) {
    vals_[index][id_] = val;
  }
 
  int snap() { return id_++; }
 
  int get(int index, int snap_id) const {
    auto it = vals_[index].upper_bound(snap_id);
    if (it == begin(vals_[index])) return 0;
    return prev(it)->second;
  }
private:
  int id_;
  vector<map<int, int>> vals_;
};


/***
 * 题意解读
调用 snap()\texttt{snap}()snap() 时，复制一份当前数组，作为「历史版本」。返回这是第几个历史版本（从 000 开始）。

调用 get(index,snapId)\texttt{get}(\textit{index}, \textit{snapId})get(index,snapId) 时，返回第 snapId\textit{snapId}snapId 个历史版本的下标为 index\textit{index}index 的元素值。

暴力？
每次调用 snap()\texttt{snap}()snap()，就复制一份数组，可以吗？

不行，最坏情况下，复制 500005000050000 次长为 500005000050000 的数组，会「超出内存限制」。

思路
假设每调用一次 set\texttt{set}set，就生成一个快照（复制一份数组）。仅仅是一个元素发生变化，就去复制整个数组，这太浪费了。

能否不复制数组呢？

换个视角，调用 set(index,val)\texttt{set}(\textit{index}, \textit{val})set(index,val) 时，不去修改数组，而是往 index\textit{index}index 的历史修改记录末尾添加一条数据：此时的快照编号和 val\textit{val}val。

举例说明：

在快照编号等于 222 时，调用 set(0,6)\texttt{set}(0, 6)set(0,6)。
在快照编号等于 333 时，调用 set(0,1)\texttt{set}(0, 1)set(0,1)。
在快照编号等于 333 时，调用 set(0,7)\texttt{set}(0, 7)set(0,7)。
在快照编号等于 555 时，调用 set(0,2)\texttt{set}(0, 2)set(0,2)。
这四次调用结束后，下标 000 的历史修改记录 history[0]=[(2,6),(3,1),(3,7),(5,2)]\textit{history}[0] = [(2,6),(3,1),(3,7),(5,2)]history[0]=[(2,6),(3,1),(3,7),(5,2)]，每个数对中的第一个数为调用 set\texttt{set}set 时的快照编号，第二个数为调用 set\texttt{set}set 时传入的 val\textit{val}val。注意历史修改记录中的快照编号是有序的。
那么：

调用 get(0,4)\texttt{get}(0, 4)get(0,4)。由于历史修改记录中的快照编号是有序的，我们可以在 history[0]\textit{history}[0]history[0] 中二分查找快照编号 ≤4\le 4≤4 的最后一条修改记录，即 (3,7)(3,7)(3,7)。修改记录中的 val=7\textit{val}=7val=7 就是答案。
调用 get(0,1)\texttt{get}(0, 1)get(0,1)。在 history[0]\textit{history}[0]history[0] 中，快照编号 ≤1\le 1≤1 的记录不存在，说明在快照编号 ≤1\le 1≤1 时，我们并没有修改下标 000 保存的元素，返回初始值 000。

作者：灵茶山艾府
链接：https://leetcode.cn/problems/snapshot-array/solutions/2756291/ji-lu-xiu-gai-li-shi-ha-xi-biao-er-fen-c-b1sh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class SnapshotArray {
public:
    SnapshotArray(int length) {

    }
    
    void set(int index, int val) {
        snaps_[index].emplace_back(snapID_,val);
    }
    
    int snap() {
        return snapID_++;
    }
    
    int get(int index, int snap_id) {
        auto& h=snaps_[index];
        // int j=ranges::lower_bound(h,make_pair(snap_id+1,0))-begin(h)-1;
        auto k=std::lower_bound(begin(h),end(h),make_pair(snap_id+1,0))-h.begin()-1;
        // auto k=ranges::lower_bound(h,make_pair(snap_id+1,0))-begin(h)-1;
        if(k>=0)
        {
            return h[k].second;
        }
        return 0;

    }
private:
    int snapID_=0;
    unordered_map<int,vector<pair<int,int>>> snaps_;//key is  the index, values are the snaps history
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */