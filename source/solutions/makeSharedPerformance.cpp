#include <chrono>
#include <iostream>
#include <memory>

constexpr int numInt = 100000000;

int main() {

    auto start = std::chrono::steady_clock::now();

    for (long long i = 0 ; i < numInt; ++i) {
        std::make_shared<int>(i);
    }

    std::chrono::duration<double> dur = std::chrono::steady_clock::now() - start;
    std::cout << "time make_shared: " <<  dur.count() << " seconds" << std::endl;

}
