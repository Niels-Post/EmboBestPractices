#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {

    std::cout << std::endl;

    std::map<std::string, int> myMap { {"Dijkstra", 1972}, {"Scott", 1976}, {"Wilkes", 1967}, {"Hamming", 1968} };
    std::vector<std::pair<std::string, int>> myFlatMap { {"Dijkstra", 1972}, {"Scott", 1976}, {"Wilkes", 1967}, {"Hamming", 1968} };
    
    std::sort(std::begin(myFlatMap), std::end(myFlatMap), [](const auto& fir, const auto& sec){ return fir.first < sec.first; }); 

    for(const auto& p : myMap) std::cout << '{' << p.first << ',' << p.second << '}';
    std::cout << std::endl;
    for(const auto& p : myFlatMap) std::cout << '{' << p.first << ',' << p.second << '}';
    
    std::cout << "\n\n";
    
    std::cout << "myMap[Scott]: " << myMap["Scott"] << std::endl;
    
    auto iter = std::lower_bound(std::begin(myFlatMap), std::end(myFlatMap), std::pair<std::string, int>("Scott", std::numeric_limits<int>::min()));
    std::cout << "myFlatMap[Scott]: " << iter->second << std::endl;
    
    std::cout << std::endl;

}
