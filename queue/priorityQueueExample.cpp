// https://en.cppreference.com/w/cpp/container/priority_queue/push
struct cmp {
  bool operator()(int a, int b) { return a < b; }
};

bool compare(int a, int b) { return a < b; }
int main() {
  priority_queue<int, vector<int>, cmp> numbers;

  vector<int> v;
  v.push_back(1);
  v.push_back(20);
  v.push_back(7);
  sort(v.begin(), v.end(), compare);

  numbers.push(1);
  numbers.push(20);
  numbers.push(7);

  cout << "Priority Queue: ";

  while (!numbers.empty()) {
    cout << numbers.top() << ", ";
    numbers.pop();
  }

  cout << endl;

  cout << "Vector: ";
  int i = 0;
  while (i < v.size()) {
    cout << v[i] << ", ";
    i++;
  }

  cout << endl;
  return 0;
}

// Output:
Priority Queue : 20, 7, 1, Vector : 1, 7, 20,