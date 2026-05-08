#include "linklist.cpp"

int main(){
    Linklist<char> h;
    h.addLast('a');
    h.addLast('b');
    h.addLast('c');
    h.addLast('d');
    h.addLast('e');
    h.printLinklist();
    std::cout<<h.getSize()<<std::endl;
    std::cout<<h.isEmpty()<<std::endl;
    std::cout<<h.getE(3)<<std::endl;
    h.insert(4,'f');
    h.printLinklist();
    h.remove(3);
    h.printLinklist();
    return 0;
}