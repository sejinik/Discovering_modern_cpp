//example라는 파일을 만든다
//myfile을 통해 example에 입력하기 가능

#include <fstream>

int main(){
    std::ofstream myfile("example.txt");
    myfile<<"Writing this to a file"<<std::endl;
    for(int i=1;i<=10;i++) myfile<<i<<std::endl;
}