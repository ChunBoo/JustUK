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
