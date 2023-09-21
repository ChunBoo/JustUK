#include <iostream>
#include <string>

using namespace std;

class BSet {
private:
  string s, s_flip;
  int cnt = 0;
  //   const int SIZE = 1e2;

public:
  BSet(int SIZE) : s(SIZE, '0'), s_flip(SIZE, '1'){};
  // BSet(){
  //     s=string(SIZE,'0');
  //     s_flip=string(SIZE,'1');
  // }
  int all() const { return cnt == int(s.size()); }
  int one() const { return cnt > 0; }
  int count() const { return cnt; }

  string toString() const { return s; }
  void fix(int idx) {
    if (s[idx] == '0') {
      s[idx] = '1';
      s_flip[idx] = '0';
      ++cnt;
    }
  }
  void unfix(int idx) {
    if (s[idx] == '1') {
      s[idx] = '0';
      s_flip[idx] = '1';
      --cnt;
    }
  }
};

int main() {
  const int SIZE = 1e2;

  BSet b(SIZE);
  b.fix(0);
  cout << b.toString();
  //   string t(10, 'x');
  //   cout << t;
}