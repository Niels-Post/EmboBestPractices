#include <chrono>
#include <iostream>
#include <memory>

constexpr int numInt = 100000000;

int main() {

    auto start = std::chrono::steady_clock::now();

    for (long long i = 0 ; i < numInt; ++i) {
        std::shared_ptr<int>(new int(i));
    }

    std::chrono::duration<double> dur = std::chrono::steady_clock::now() - start;
    std::cout << "time shared_ptr: " <<  dur.count() << " seconds" << std::endl;

}
