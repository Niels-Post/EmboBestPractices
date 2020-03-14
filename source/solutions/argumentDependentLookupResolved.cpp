#include <iostream>
#include <vector>

namespace Bad {
    
    struct Number { 
        int m; 
    };
    
}

namespace Util {
    
    bool operator==(int, Bad::Number) {   
        return true; 
    } 

    void compareSize() {
        Bad::Number badNumber{5};                         
        std::vector<int> vec{1, 2, 3, 4, 5};
        
        std::cout << std::boolalpha << std::endl;
        
        std::cout << "5 == badNumber: " <<                    
                     (5 == badNumber) << std::endl;                
        std::cout << "vec.size() == badNumber: " << 
                     (vec.size() == badNumber) << std::endl; 
        
        std::cout << std::endl;
    }
}

int main() {
   
   Util::compareSize();

}
