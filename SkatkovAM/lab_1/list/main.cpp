#include "List.h"
template <typename T>
void print(const List<T>& toPrint) {
    typename List<T>::iterator it = toPrint.first();
    while(it != nullptr) {
        std::cout<<*it<<' ';
        ++it;
    }
}


int main() {
    List<int> l(5,5);
    std::cout<<std::endl;
    print(l);
    l.insert(3,10);
    std::cout<<std::endl;
    print(l);
    std::cout<<std::endl;
    l.push_back(100);
    print(l);
    std::cout<<std::endl;
}