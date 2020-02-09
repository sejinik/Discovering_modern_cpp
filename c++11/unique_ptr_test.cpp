// 스마트포인터 중 하나
// 사용 시 스스로 메모리를 해제 해 준다
// unique_ptr<type> name{동적으로 할당 한 주소} => 동적으로 할당하지 않은 주소를 넣으면 마지막에 메모리를 해지하려하므로 오류
// 유니트포인터는 대입연산 불가능하다
// 오직 move를 통해서만 이동 가능

#include <iostream>
#include <memory>

using namespace std;

struct X {
    static int c;
    X(){ cout<<"X [ " <<++c<< " ] constructed at address "<< this<<endl;}
    ~X(){cout<<"X [ " <<c--<< " ] destructed at address "<< this<<endl;}
};

int X::c=0;

template<typename T>
void vector_add(unsigned size, const T& v1, const T& v2, T& s){
    for(unsigned i=0;i<size;++i) s[i]=v1[i]+v2[i];
}

unique_ptr<double> f(){
    return unique_ptr<double>{new double};
}

int main(){
    unique_ptr<double> dp{new double};
    *dp=7;

    double* raw_dp = dp.get();

    unique_ptr<double> dp2{move(dp)};
    dp2 = move(dp);

    unique_ptr<double> dp3;
    dp3 = f();

    unique_ptr<double[]> da{new double[3]};
    for(unsigned i=0; i<3;++i) da[i]=i+2;

    unique_ptr<double[]> x{new double[3]},y{new double[3]},sum{new double[3]};
    for( unsigned i=0; i<3;++i) x[i]=i+2,y[i]=4-2*i;
    vector_add(3,x,y,sum);
    for(unsigned i=0; i<3;++i) cout<<sum[i]<<", ";
}