#include<iostream>
#include "pthread.h"
#include<string>


struct InputType
{
    std::string s;
    size_t pos;
    size_t len;
};

void* thread_subStr(void* arg)
{
    InputType *in=(InputType*)(arg);
    std::cout<<in->s.substr(in->pos,in->len)<<'\n';
    return nullptr;
}


int main()
{
    InputType in;
    in.s="Hello,World";
    in.pos=6;
    in.len=in.s.size()-in.pos;

    //create the thread
    pthread_t tid;
    pthread_create(&tid,NULL,thread_subStr,&in);
    //wait for the thread run to end
    void* res;
    pthread_join(tid,&res);

    return 0;
}

