#include <iostream>
#include <list>
#include <stdexcept>
template<typename E>
class MyLinkedStack{
    private:
        std::list<E> list;

    public:
        //进栈
        void push(const E &e){
            list.push_back(e);
        }
        //出栈
        E pop(){
            if(list.empty()){
                throw std::runtime_error("Stack is empty!");
            }
            E val=list.back();
            list.pop_back();
            return val; 
        }
        int getPopIndex(){
            return list.size();
        }
        //判断是否为空
        bool isEmpty(){
            return list.empty();
        }
        //输出
        void printStack(){
            for(E i:list){
                std::cout<<i<<" ";
            }
        }
};