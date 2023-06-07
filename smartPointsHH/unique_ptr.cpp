#include<iostream>
#include<memory>

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

}
int main()
{
    // foo();    
    auto f=std::make_unique<CFoo>();
    cout<<"\nCall the bar()\n";
    bar(std::move(f));
    cout<<"\t Leaving foo()\n";
}