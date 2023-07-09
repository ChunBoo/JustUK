#include<iostream>
#include<memory>
#include<cassert>
using std::cout;

class CFoo
{
    public:
        CFoo(){
            cout<<"Create object for CFoo.\n";
        }
        ~CFoo()
        {
            cout<<"Destroy object for CFoo.\n";
        }
        void doSomething()
        {
            cout<<"Calling doSomething of CFoo.\n";
        }
};


void bar(std::unique_ptr<CFoo> f)
{
    f->doSomething();
    cout<<"Leaving bar() \n";
}

void foo()
{
    cout<<"Enter foo()\n";
    {
        auto e=std::make_unique<CFoo>();
    }
    cout<<"Leaving foo()\n";
}
int main()
{
    // foo();    
    auto f=std::make_unique<CFoo>();
    cout<<"\nCall the bar()\n";
    bar(std::move(f));
    // cout<<"\t Leaving foo()\n";
    assert(f!=nullptr);
    f->doSomething();
    // auto e2=std::move(f);
    // e2->doSomething();
    cout<<"---------------\n";
    foo();
}