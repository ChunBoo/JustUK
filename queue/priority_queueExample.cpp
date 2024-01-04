/**
In C++, the std::priority_queue is a container adapter that uses a greater (not
less) comparison function by default. This means that by default, it creates a
max-heap, not a min-heap.

The elements in a std::priority_queue are ordered according to their priority,
with the highest priority element at the top of the queue (i.e., at the front of
the queue when you call top()).

In the case of a max-heap, the "highest priority" is the maximum element, so the
largest element is always at the top of the queue.
*/
#include <iostream>
#include <queue>

int main() {
  std::priority_queue<int> pq;

  pq.push(3);
  pq.push(5);
  pq.push(1);

  // Prints: 5 3 1
  while (!pq.empty()) {
    std::cout << pq.top() << " ";
    pq.pop();
  }

  return 0;
}