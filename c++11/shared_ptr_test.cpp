// shared_ptr은 공통으로 사용하는 메모리를 관리한다
// 현재 해당 메모리를 몇명이 사용하는지 count 해주고
// 0명이 된다면 자동으로 delete를 해서 해지시켜준다
// make_shared를 통해 만들어야 효율적이다

#include <iostream>
#include <memory>

using namespace std;

struct X
{
    static int c;
    int i=3;
};

int X:: c=0;

shared_ptr<double> f(){
    auto p1 = make_shared<double>();
    shared_ptr<double> p2{new double}, p3=p2;
    cout<< "p3.use_count() = "<<p3.use_count()<<endl;
    return p3;
}

int main(){
    X x;
    shared_ptr<double> p1 = f();
    cout<<"p1.use_count() = "<<p1.use_count()<<endl;

    shared_ptr<X> p2(new X);

    cout<< "@p2 = "<<p2<<endl;
}
