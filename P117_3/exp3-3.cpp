#include "sqqueue.cpp"
int main(){
    sqqueue<char> s;
    std::cout<<s.isempty()<<std::endl;
    s.enqueue('a');
    s.enqueue('b');
    s.enqueue('c');
    std::cout<<s.dequeue()<<std::endl;
    s.enqueue('d');
    s.enqueue('e');
    s.enqueue('f');
    std::cout<<s.getTailIndex()<<std::endl;
    return 0;
}