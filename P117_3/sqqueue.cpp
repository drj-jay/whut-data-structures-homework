#include <iostream>
#include <stdexcept>
#include <vector>
#include <utility>
template <typename E>
class sqqueue{
private: 
    int count;
    int head;
    int tail;
    std::vector<E> arr;
    void resize(int NewCapacity){
        std::vector<E> newArr(NewCapacity);
        for(int i=0;i<this->count;i++){
            newArr[i]=arr[(head+i)%arr.size()];
        }
        arr=std::move(newArr);
        tail=count;
        head=0;
    }
public:
    sqqueue(int capacity=10):count(0),head(0),tail(0),arr(capacity){};
    //入队
    void enqueue(const E &e){
        if(isfull()){
            resize(arr.size()*2);
        }
        arr[tail]=e;
        tail=(tail+1)%arr.size();
        count++;
    }
    bool isfull(){
        return count==arr.size();
    }
    bool  isempty(){
        return count==0;
    }
    //出队
    E dequeue(){
        if(isempty()){
            throw std::out_of_range("is empty!");
        }
        E ret=arr[head];
        head=(head+1)%arr.size();
        count--;
        if(count==arr.size()/4&&count>0){
            resize(arr.size()/2);
        }
        return ret;
    }
    int getHeadIndex(){
        return head;
    }
    int getTailIndex(){
        return tail;
    }
    //打印
    void printSqqueue(){
        for(int i=0;i<count;i++){
            std::cout<<arr[(i+head)%arr.size()]<<" ";
        }
    }
};