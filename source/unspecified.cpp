#include <iostream>

void func(int fir, int sec) {
    std::cout << "(" << fir << "," << sec << ")" << std::endl;
}

int main(){
    int i = 0;
    func(i++, i++);
}
