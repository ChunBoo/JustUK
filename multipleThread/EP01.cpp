#include<iostream>
#include<mingw.thread.h>
#include<unistd.h>
int a=1;
void run()
{
    a+=1;
}

void multipleThread()
{
    std::thread t1(run);
    std::thread t2(run);
    t1.join();
    t2.join();
    std::cout<<a;
}

void run(bool child){
    a+=child?2:1;
}

void multipleProcess()
{
    a+=1;
    pid_t pid=fork();//parallel universe
    run(pid==0);
    std::cout<<a<<'\n';

    
}
int main()
{
    // multipleThread();
    multipleProcess();
}