/*
Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().
Note:
We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.

Example 1:

Input: nums = [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
*/

class Foo {
public:
    private:
     mtx2,mtx3;
    Foo() {
        mtx2.lock();
        mtx3.lock();
        // mtx1.unlock();
    }

    void first(function<void()> printFirst) {
        // mtx1.lock();
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        mtx2.unlock();
    }

    void second(function<void()> printSecond) {
        mtx2.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        mtx3.unlock();
    }

    void third(function<void()> printThird) {
        mtx3.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        // mtx1.unlock();
    }
};