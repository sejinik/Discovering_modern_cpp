// NDEBUG를 선언해두면 assert가 모두 무시됨
// assert는 해당 조건이 참이 아니면 프로그램이 종료됨
// 방어적 프로그래밍 => 최대한 많은 속성을 테스트하라!

#define NDEBUG
#include <cassert>
#include <iostream>
using namespace std;

double square_root(double x){
    double result = x;
    assert(result>=0.0 && "Value must be non-negative");
    return result;
}
int main(){
    square_root(-3);
    return 0;
}