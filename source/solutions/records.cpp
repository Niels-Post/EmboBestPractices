#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool compareInsensitive(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) return false;
    for (std::string::size_type i = 0; i < a.size(); ++i) {
        if (std::tolower(a[i]) != std::tolower(b[i])) return false;
    }
    return true;
}


struct Rec {                                                     
    std::string name;
    std::string addr;
    int id;         
};

int main() {
    
    std::cout << std::endl;
    
    std::vector<Rec> vr{ {"Grimm", "Munich", 1},                 
                         {"huber", "Stuttgart", 2},
                         {"Smith", "Rottenburg", 3},
                         {"black", "Hanover", 4} };
                         
    std::string name = "smith";
    
    auto rec = std::find_if(vr.begin(), vr.end(), [&name](Rec& r) { return compareInsensitive(r.name, name); });
    
    if (rec != vr.end()) {
        std::cout << rec->name << ",  " << rec->addr << ", " << rec->id << std::endl;
    }
    
    std::cout << std::endl;
    
}
