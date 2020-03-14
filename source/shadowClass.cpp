#include <iostream>
#include <string>

struct Base {
    void shadow(std::string) {                           
        std::cout << "Base::shadow" << std::endl;       
    }
};

struct Derived: Base {
    void shadow(int) {                                  
        std::cout << "Derived::shadow" << std::endl;    
    }
};

int main() {
    
    std::cout << std::endl;
    
    Derived derived;
    
    derived.shadow(std::string{});                      
    derived.shadow(int{});                              
    
    std::cout << std::endl;
    
}
