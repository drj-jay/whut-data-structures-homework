#include <iostream>
#include <stdexcept>
template <typename E>
class Sqlist {
private:
    E* data;
    int size;//当前元素个数
    int capacity;//当前最大容量
    static const int INIT_CAPACITY = 10;
public:
    Sqlist():size(0),capacity(INIT_CAPACITY) {
        this->data = new E[capacity];
    }
    Sqlist(int capacity){
        this->capacity=capacity;
        this->size=0;
        this->data=new E[capacity];
    }
    ~Sqlist() {
        delete[] data;
    }
    //增
    void addLast(E e){
        if(size==capacity){
            resize(2*capacity);
        }
        data[size]=e;
        size++;
    }
    void insert(int index,E e){
        checkIndex(index);
        if(size==capacity){
            resize(2*capacity);
        }
        for(int i=size-1;i>=index-1;i--){
            data[i+1]=data[i];
        }
        data[index-1]=e;
        size++;
    }
    //检查index位置是否可以添加元素
    void checkIndex(int index){
        if(index<1||index>size+1){
            throw std::out_of_range("index out of range");
        }
    }
    //检查index位置是否可以访问元素
    void checkIndexPosition(int index){
        if(index<1||index>size){
            throw std::out_of_range("index out of range");
        }
    }
    //扩大容量
    void resize(int newCapacity){
        E* temp=new E[newCapacity];
        for(int i=0;i<size;i++){
            temp[i]=data[i];
        }
        delete[] data;
        data=temp;
        capacity=newCapacity;
    }
    //删
    E removeLast(){
        if(size==0){
            throw std::out_of_range("list is empty");
        }
        E deleted=data[--size];
        data[size]=E();
        if(size<=capacity/4&&capacity>INIT_CAPACITY){
            resize(capacity/2);
        }
        return deleted;
    }
    E remove(int index){
        checkIndexPosition(index);
        E deleted=data[index-1];
        for(int i=index-1;i<size-1;i++){
            data[i]=data[i+1];
        }
        data[size-1]=E();
        size--;
        if(size<=capacity/4&&capacity>INIT_CAPACITY){
            resize(capacity/2);
        }
        return deleted;
    }
    //改
    E set(int index,E e){
        checkIndexPosition(index);
        E old=data[index-1];
        data[index-1]=e;
        return old;
    }
    //查
    E getE(int index){
        checkIndexPosition(index);
        return data[index-1];
    }
    void getIndex(E e){
        for(int i=0;i<size;i++){
            if(data[i]==e){
                std::cout<<i+1<<" ";
            }
        }
        std::cout<<std::endl;
    }
    //获取当前元素个数
    int getSize(){
        return size;
    }
    //打印
    void printSqList(){
        for(int i=0;i<size;i++){
            std::cout<<data[i]<<" ";
        }
        std::cout<<std::endl;
    }
    //判断是否为空
    bool isEmpty(){
        return size==0;
    }
};    