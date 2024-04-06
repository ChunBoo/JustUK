#include<iostream>

using namespace std;



void foo(int x)
{
    int y=__builtin_clz(x);
    int z=__builtin_ctz(x);
    cout<<y<<'\n';
    cout<<z;

}

int main(){
    foo(2);
}