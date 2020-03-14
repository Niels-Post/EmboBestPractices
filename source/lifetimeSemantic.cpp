// lifetimeSemantic.cpp

#include <iostream>
#include <memory>

using std::cout;

void asSmartPointerGood(std::shared_ptr<int>& shr) {
    cout << "asSmartPointerGood \n";
    cout << "    shr.use_count(): " << shr.use_count() << '\n';  
    shr.reset(new int(2011));                                     
    cout << "    shr.use_count(): " << shr.use_count() << '\n';     
    cout << "asSmartPointerGood \n";
}

void asSmartPointerBad(std::shared_ptr<int>& shr) {
    cout << "asSmartPointerBad(secSha) \n";
    *shr += 19;
}

int main() {
  
    cout << '\n';
  
    auto firSha = std::make_shared<int>(1998);
    auto secSha = firSha;
    cout << "firSha.use_count(): " << firSha.use_count() << '\n'; 
  
    cout << '\n';
  
    asSmartPointerGood(firSha);                                   

    cout << '\n';
  
    cout << "*firSha: " << *firSha << '\n';
    cout << "firSha.use_count(): " << firSha.use_count() << '\n';
  
    cout << '\n';
  
    cout << "*secSha: " << *secSha << '\n';
    cout << "secSha.use_count(): " << secSha.use_count() << '\n';
  
    cout << '\n';
  
    asSmartPointerBad(secSha); 
    cout << "*secSha: " << *secSha << '\n';
  
    cout << '\n';
  
}
