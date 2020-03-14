#include <mutex>
#include <iostream>

template <typename T>
class MyGuard {
public:
    MyGuard(T& m): myMutex(m) {
        myMutex.lock();
        std::cout << "lock" << std::endl;
    }
    ~MyGuard() {
        myMutex.unlock();
        std::cout << "unlock" << std::endl;
    }
private:
    T& myMutex;
};

int main() {
	
    std::cout << std::endl;
	
    std::mutex m;
    MyGuard<std::mutex> myLock{m};                        
    std::cout << "CRITICAL SECTION" << std::endl;  
  
    std::cout << std::endl;

}     
