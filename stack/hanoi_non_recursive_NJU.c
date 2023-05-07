#include<iostream>
#include <cassert>
using std::cout;
typedef struct 
{
    int pc,n;
    char from,to,via;
}Frame;

#define call(...) ({*(++top)=(Frame) {.pc=0,__VA_ARGS__};})
#define ret() ({top--;})
#define goto(loc) ({f->pc=(loc)-1;})


void hanoi(int n,char from,char to,char via)
{
    Frame stk[64],*top=stk-1;
    call(n,from,to,via);
    for(Frame *f;(f=top)>=stk;f->pc++)
    {
        n=f->n;
        from=f->from;
        to=f->to;
        via=f->via;
        switch(f->pc)
        {
            case 0:
                if(n==1)
                {
                    cout<<from<<" -> "<<to<<'\n';
                    goto(4);
                }
                break;
            case 1:
                call(n-1,from,via,to);
                break;
            case 2:
                call(1,from,to,via);
                break;
            case 3:
                call(n-1,via,to,from);
                break;
            case 4:
                ret();
                break;
            default:
                assert(0);
        }
    }
}

int main()
{
    hanoi(3,'A','C','B');
}
