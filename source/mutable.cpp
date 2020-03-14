#include <iostream>

struct Immutable {
    mutable int val{12};            
    void canNotModify() const {
        val = 13;
    }
};

int main() {
    
    std::cout << std::endl;
    
    const Immutable immu;
    std::cout << "val: " << immu.val << std::endl;
    immu.canNotModify();            
    std::cout << "val: " << immu.val << std::endl;
    
    std::cout << std::endl;
    
}
