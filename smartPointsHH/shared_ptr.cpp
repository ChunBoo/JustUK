#include<iostream>
#include<memory>

using std::cout;


class CEntity{
    public:
        CEntity(){
            cout<<"Create the object of CEntity.\n";
        }
        ~CEntity()
        {
            cout<<"Destroy the object of CEntity.\n";
        }
};


void foo()
{
    auto e1=std::make_shared<CEntity>();
    cout<<e1.use_count()<<'\n';   //1
    {
        auto e2=e1;
        cout<<e1.use_count()<<'\n';  //2
        auto e3=std::move(e2);
        cout<<e1.use_count()<<'\n';  //2
    }
    cout<<e1.use_count()<<'\n';  //1
}

int main()
{
    foo();
}