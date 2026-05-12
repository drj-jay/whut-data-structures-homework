#include "listack.cpp"
int main(){
    MyLinkedStack<char> s;
    std::cout<<s.isEmpty()<<std::endl;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');
    std::cout<<s.isEmpty()<<std::endl;
    s.printStack();
    std::cout<<std::endl;
    std::cout<<s.isEmpty()<<std::endl;
    return 0;
}