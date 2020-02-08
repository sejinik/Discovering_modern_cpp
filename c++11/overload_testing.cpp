#include <iostream>

using std::cout;

// 같은 이름을 가진 함수 오버로딩
// 1. 인수 타입과 정확히 일치하는것이 있다면 해당 함수 실행
// 2. 암시적 변환 후 일치하는 함수가 있다면
// 2-1) 0개 == 오류
//      1개 == 해당 함수 실행
//      여러개 == 오류 (모호한 호출)

void f(int& x){ cout<< "int&\n";}
void f(const int&x) {cout<< "const int&\n";}
int main(){
    int i=3;
    const int ci =4;
    f(i);
    f(ci);
    f(3);
}