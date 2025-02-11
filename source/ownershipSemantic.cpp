// ownershipSemantic.cpp

#include <iostream>
#include <memory>
#include <utility>

class MyInt {
public:
    explicit MyInt(int val): myInt(val){}
    ~MyInt() noexcept {
        std::cout << myInt << std::endl;
    }
private:
    int myInt;
};

void funcCopy(MyInt myInt) {}

void funcPtr(MyInt* myInt) {}

void funcRef(MyInt& myInt) {}

void funcUniqPtr(std::unique_ptr<MyInt> myInt) {}

void funcSharedPtr(std::shared_ptr<MyInt> myInt) {}

int main() {
    
    std::cout << std::endl;
    
    std::cout << "=== Begin" << std::endl;
    
    MyInt myInt{1998};
    
    MyInt* myIntPtr = &myInt;
    
    MyInt& myIntRef = myInt;
    
    auto uniqPtr = std::make_unique<MyInt>(2011);
    
    auto sharedPtr = std::make_shared<MyInt>(2014);
    
    funcCopy(myInt);
    
    funcPtr(myIntPtr);
    
    funcRef(myIntRef);
    
    funcUniqPtr(std::move(uniqPtr));
    
    funcSharedPtr(sharedPtr);
    
    std::cout << "==== End" << std::endl;
    
    std::cout << std::endl;
    
}
