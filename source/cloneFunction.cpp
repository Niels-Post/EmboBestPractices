#include <iostream>
#include <memory>
#include <string>

struct Base { // GOOD: base class suppresses copying
    Base() = default;
    Base(const Base&) = delete;
    Base& operator=(const Base&) = delete;
    virtual std::unique_ptr<Base> clone() { return std::make_unique<Base>(); }
    virtual std::string getName() const { return "Base"; }
};

struct Derived : public Base {
    Derived() = default;
    std::string str{};      // add a data member
    std::unique_ptr<Base> clone() override { return std::make_unique<Derived>(); }
    virtual std::string getName() const { return "Derived"; }
};

int main() {
    
    std::cout << std::endl;

    auto base1 = std::make_unique<Base>();
    auto base2 = base1->clone();
    std::cout << "base1->getName(): " << base1->getName() << std::endl;
    std::cout << "base2->getName(): " << base2->getName() << std::endl;
    
    auto derived1 = std::make_unique<Derived>();
    auto derived2 = derived1->clone();
    std::cout << "derived1->getName(): " << derived1->getName() << std::endl;
    std::cout << "derived2->getName(): " << derived2->getName() << std::endl;
    
    std::cout << std::endl;

}
