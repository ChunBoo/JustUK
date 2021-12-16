前言
由于C++98/03标准没有提供线程库，所以在C++11之前一般使用的是平台特定的线程库，或者干脆使用第三方库。个人而言，以前用过Linux的Pthreads库，也看过过Win API的线程相关函数，都是以一种C风格的方式来传递参数，即输入和输出类型均为void*，由于C中指针类型本质是一样的，可以进行强制类型转换，所以这种方式可以输入和输出任意数量的参数，只不过比较蹩脚，这里以实现一个分割字符串的线程函数为例。

C风格的方式(使用pthread)
// pthread_demo.cc
#include <iostream>
#include <string>
#include <pthread.h>

struct InputType {
    std::string s;
    size_t pos;
    size_t len;
};

void* thread_substr(void* arg) {
    InputType* p = (InputType*) arg;  // 强制转换后还原输入参数
    std::cout << p->s.substr(p->pos, p->len) << std::endl;
    return NULL;
}

int main() {
    // 1. 将输入参数封装成单个对象
    InputType in;
    in.s = "Hello World!";
    in.pos = 6;
    in.len = in.s.size() - in.pos;
    // 2. 创建pthread线程
    pthread_t tid;
    pthread_create(&tid, NULL, thread_substr, &in);
    // 3. 等待pthread线程运行结束
    void* res;
    pthread_join(tid, &res);
    return 0;
}
编译时需要加上-pthread选项

xyz@ubuntu:~$ g++ pthread_substr.cc -pthread
xyz@ubuntu:~$ ./a.out 
World!
首先需要说明的一点是，pthread_xxx()函数成功则返回0，否则返回错误码，对于这种C风格API，实际编程中检查返回值是必要的，否则出错之后很难定位。
可以发现这种T*->void*的方式非常麻烦，而且平台相关的API往往还需要详尽的其他参数，比如pthread_create的第2个参数代表线程属性，
比如优先级/调度策略/栈地址大小，参考我之前写的博客Linux的POSIX线程属性，这个参数的配置复杂程度不亚于线程操作。
而Win API则是提供了好几个参数，用平台特定的宏OR运算来一个个指定，参见CreateThread

HANDLE WINAPI CreateThread(
  _In_opt_  LPSECURITY_ATTRIBUTES  lpThreadAttributes,
  _In_      SIZE_T                 dwStackSize,
  _In_      LPTHREAD_START_ROUTINE lpStartAddress,
  _In_opt_  LPVOID                 lpParameter,
  _In_      DWORD                  dwCreationFlags,
  _Out_opt_ LPDWORD                lpThreadId
);
实际调用时一般会像上述函数声明一样把CreateThread分好几行写，并且分别给每个参数后面加一段注释，表明这里设置NULL或0是默认定义了什么参数，从而增加可读性。
虽然Win API往往是通过宏的OR运算来设置参数，而pthread则是通过库函数来设置。
一般来说，这些参数采用默认就好了，底层API的特点是提供了很大的灵活性，但是使用起来非常麻烦，往往用户会自己对底层API做一些简单的封装，
尤其是C++可以直接调用C API，然后用默认函数参数的特性来让用户调用时少写几个默认参数。

C++11的方式
C++11新增了可变模板参数特性，使得实现刚才那段代码非常容易。C++11的实现如下

// cpp11_thread_demo.cc
#include <iostream>
#include <string>
#include <thread>

void thread_substr(const std::string& s, size_t pos, size_t len) {
    std::cout << s.substr(pos, len) << std::endl;
}

int main() {
    std::string s = "Hello World";
    std::thread t(thread_substr, s, 6, s.size() - 6);
    t.join();
    return 0;
}
虽然使用的是C++标准库，但是用g++编译时还是需要加上-pthread选项。

xyz@ubuntu:~$ g++ -std=c++11 cpp11_thread_demo.cc -pthread
xyz@ubuntu:~$ ./a.out 
World
可以发现C++线程库简化了线程创建和连接的操作，去掉了平台特定属性的设置，如果实在时要对线程属性进行精确控制，C++线程库也提供了
thread::native_handle函数来取得平台特定的线程句柄，比如对pthread而言就是pthread_t类型，对WinAPI而言就是HANDLE类型。
需要注意的是，对于类成员函数，传入方式应该像下面这样

struct Object {
    void func(int i, double d) { std::cout << i << " " << d << std::endl; }
};

int main() {
    Object obj;
    std::thread t(&Object::func, obj, 1, 3.14);
    t.join();
    return 0;
}
第一个参数是类成员函数的地址（类型为void (Object::*)(int, double)），第二个参数是类的对象，之后才是成员函数的参数。

线程的分离(detach)和连接(join)
我之前的代码均是2步：1. 构造线程对象；2. 调用对象的join()方法。
在线程对象被成功创建后（即传入了一个线程函数和合适的参数），线程对象和线程函数是绑定在一起的，但是线程函数和父线程函数是分离的（即并行执行）。但问题在于，父线程函数结束执行时，函数作用域内的所有栈上的对象都会销毁。

void func() {
    std::thread t{ [] { std::cout << "Hello world!" << std::endl; } };                             
}   
对上述代码而言，func()在构造线程对象t后会立即结束，而与t相关的线程函数会花一段时间执行完，因此在func()结束时，t离开了作用域而销毁，而线程函数仍在执行，此时便会出错。

terminate called without an active exception
Aborted (core dumped)
所以在成功创建线程后，必须得执行连接或分离操作。

join()
对线程进行连接操作类似于Linux对进程的wait()操作，如果父线程调用join()时线程函数已经执行完毕，立刻取得线程函数的返回值，否则一直等待线程函数执行完毕才能执行下一句。
void func() {
    std::thread t{ [] {
        sleep(1);  // unistd.h
        std::cout << "Hello world!" << std::endl;
    } };
    t.join();
    std::cout << "thread ok!" << std::endl;
}
xyz@ubuntu:~$ g++ test.cc -std=c++11 -pthread
xyz@ubuntu:~$ ./a.out 
Hello world!
thread ok!
可以看到，虽然子线程是休眠了1秒后才打印的，但是父线程是在它之后才打印。
使用join()典型的情况是：创建多个线程用来执行类似的任务，父线程等所有子线程完成任务后才继续执行。比如创建多个线程进行爬虫，等所有数据都爬完了再一起做处理。

detach()
回顾之前提到的线程对象销毁了而线程函数仍在执行的状态，如果线程对象调用了detach()方法，那么它就可以“寿终正寝”了，即使之后它销毁了，线程函数仍然可以继续执行。
使用detach()典型的情况是：在父线程中创建完子线程去执行各自的任务，然后父线程继续干自己的事情。比如每个子线程安排1个窗口来售票，执行完毕会释放窗口。父线程不用等待子线程结束时就要继续接客，每次接客时检查是否有空余窗口，若有则再创建子线程。
谨慎分离线程
将线程分离时需要十分谨慎。
首先，如果你在main()函数内部创建一个线程，然后分离，之后结束main()函数。由于main()函数返回时程序也会结束运行，即进程终止。进程终止意味着回收进程占用的虚拟内存空间，自然创建的子线程也不会脱离进程而运行。

int main() {
    std::thread t{ []{ std::cout << "Hello world!" << std::endl; } };
    t.detach();
    return 0;
}
所以像上面这段代码执行结果会是什么也不输出。
更需要注意的是下面这种情况

#include <stdio.h>
#include <unistd.h>
#include <thread>  // for sleep()

void thread_func(const char* s) {
    sleep(1);  // 让func()先退出
    puts(s);
}

void func() {
    char s[] = "hello";
    std::thread t(thread_func, s);
    t.detach();
}

int main() {
    func();
    sleep(2);  // 等待线程执行完毕
    return 0;
}
注意字符数组s在func()调用结束之后就被回收了，而线程函数接收的参数s指向的是一段被回收的内存，访问已经被回收的内存会产生预料之外的行为。
类似的行为还有，线程函数接收T&或者T*，而T类型的对象是分类在栈上的，如果线程分离后线程函数还在执行，函数参数所引用或指向的对象就已经被回收了。
一种解决方式是拷贝一份数据，虽然这样看起来开销比较大。比如接收一个vector作为参数，如果vector包含元素很多，复制起来的开销不小，而且大数据量的复制可能抛出bad_alloc异常。
另一种解决方式是在堆上new动态申请内存，然后传递指针。这样的话内存的释放就要交给线程函数了，那么在线程函数里就得十分小心谨慎地添加delete语句。
熟悉C++的同学自然可以想到，可以利用RAII来管理动态内存。将STL容器/智能指针（shared_ptr和unique_ptr）/字符串类（string）作为线程函数的参数。

使用RAII保证线程的join操作
    std::thread t(func);
    do_sth();
    t.join();
上述代码是典型的套路：C++11中创建子线程，之后主线程做自己的事情，之后等待子线程执行完毕。
但是问题在于do_sth()可能会抛出异常，如果你要捕获异常进行处理，代码就变成了这样

    std::thread t;
    try {
        t = std::thread(func);
        do_sth();
        t.join();
    } catch (std::exception& e) {
        if (t.joinable()) {
            t.join();
        }
        std::cerr << e.what() << "\n";
    }
假如有多个catch语句，那么每个catch语句都要手动join线程。理想的状况是线程对象t销毁之前就让它执行join()操作。
因此可以定义下面这样的类

class scoped_thread {
    std::thread t;
public:
    scoped_thread(std::thread t_) : t(std::move(t_)) {
        if (!t.joinable()) {
            throw std::logic_error("No thread!");
        }
    }
    ~scoped_thread() {
        t.join();
    }
    scoped_thread(const scoped_thread&) = delete;
    scoped_thread& operator=(const scoped_thread&) = delete;
};
然后创建线程的函数变为

    try {
        scoped_thread t(std::thread(func));
        do_sth();
    } catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }
上述代码使用了移动操作将线程的所有权转移到了scoped_thread对象内部的std::thread对象中，也可以先定义std::thread t(func);再构造scoped_thread st(std::move(t));，此时t就失去了对线程的控制权，t也变成了不可join的状态。由于scoped_thread内部的线程对象是私有的，所以除了析构函数没有任何措施能够对线程执行join操作。而析构函数是在scoped_thread对象离开作用域时自动调用的，所以相当于此时自动join。

作者：哈莉_奎茵
链接：https://www.jianshu.com/p/7e5415879ec3
来源：简书
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。