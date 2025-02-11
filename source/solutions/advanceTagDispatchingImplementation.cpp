#include <iterator>
#include <forward_list>
#include <list>
#include <vector>
#include <iostream>

template <typename InputIterator, typename Distance>
void advance_impl(InputIterator& i, Distance n, std::input_iterator_tag) {
    while (n--) ++i;
}

template <typename BidirectionalIterator, typename Distance>
void advance_impl(BidirectionalIterator& i, Distance n, std::bidirectional_iterator_tag) {
    if (n >= 0) 
        while (n--) ++i;
    else 
        while (n++) --i;
}

template <typename RandomAccessIterator, typename Distance>
void advance_impl(RandomAccessIterator& i, Distance n, std::random_access_iterator_tag) {
    i += n;
}

template <typename InputIterator, typename Distance>
void advance_(InputIterator& i, Distance n) {
    typename std::iterator_traits<InputIterator>::iterator_category category;
    advance_impl(i, n, category);
}
  
int main(){
    
    std::cout << std::endl;
    
    std::vector<int> myVec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto myVecIt = myVec.begin();
    std::cout << "*myVecIt: " << *myVecIt << std::endl;
    advance_(myVecIt, 5);
    std::cout << "*myVecIt: " << *myVecIt << std::endl;
    
    std::cout << std::endl;
    
    std::list<int> myList{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto myListIt = myList.begin();
    std::cout << "*myListIt: " << *myListIt << std::endl;
    advance_(myListIt, 5);
    std::cout << "*myListIt: " << *myListIt << std::endl;
    
    std::cout << std::endl;
    
    std::forward_list<int> myForwardList{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto myForwardListIt = myForwardList.begin();
    std::cout << "*myForwardListIt: " << *myForwardListIt << std::endl;
    advance_(myForwardListIt, 5);
    std::cout << "*myForwardListIt: " << *myForwardListIt << std::endl;
    
    std::cout << std::endl;
    
}
