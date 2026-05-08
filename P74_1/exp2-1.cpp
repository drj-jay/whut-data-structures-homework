#include "sqlist.cpp"

int main(){
    Sqlist<char> L;
    L.addLast('a');
    L.addLast('b');
    L.addLast('c');
    L.addLast('d');
    L.addLast('e');
    L.printSqList();
    std::cout<<L.isEmpty()<<std::endl;
    std::cout<<L.getE(3)<<std::endl;
    L.getIndex('a');
    L.insert(4,'f');
    L.printSqList();
    L.remove(3);
    L.printSqList();
    return 0;
}