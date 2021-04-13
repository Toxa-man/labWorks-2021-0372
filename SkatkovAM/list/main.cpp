#include "List.h"
template <typename T>
void print(const List<T>& toPrint) {
    typename List<T>::iterator it = toPrint.first();
    while(it != nullptr) {
        std::cout<<*it<<' ';
        ++it;
    }
    std::cout<<std::endl;
}


int main() {
    List<int> l(0);
//    l.insert(0,5);
    print(l);
}