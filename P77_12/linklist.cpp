#include <iostream>
#include <stdexcept>
template <typename E>
class Linklist {
    private:
        struct Node{
            E data;
            Node* next;
            Node(E value):data(value),next(nullptr){};
        };
        Node* head;
        Node* tail;
        int size;
    public:
        Linklist():size(0){
            head=new Node(E());
            tail=head;
        };
        ~Linklist(){
            Node* current=head;
            while(current!=nullptr){
                Node* temp=current->next;
                delete current;
                current=temp;
            }
        }
        //增
            //头插
        void addFirst(E e){
            Node* newNode=new Node(e);
            newNode->next=head->next;
            head->next=newNode;
            if(size==0){
                tail=newNode;
            }
            size++;
        }
            //尾插
        void addLast(E e){
            Node* newNode=new Node(e);
            tail->next=newNode;
            tail=newNode;
            size++;
        } 
            //插入
        void insert(int index,E e){
            checkIndex(index);
            Node* newNode=new Node(e);
            Node* current=head;
            for(int i=1;i<index;i++){
                current=current->next;
            }
            newNode->next=current->next;
            current->next=newNode;
            if(newNode->next==nullptr){
                tail=newNode;
            }
            size++;
        }
            //检查index位置是否可以添加元素
        void checkIndex(int index){
            if(index<1||index>size+1){
                throw std::out_of_range("index out of range");
            }
        }
        void checkIndexPosition(int index){
            if(index<1||index>size){
                throw std::out_of_range("index out of range");
            }
        }
        //删
            //头删
        E removeFirst(){
            if(size==0){
                throw std::out_of_range("list is empty");
            }
            Node* temp=head->next;
            head->next=temp->next;
            E old=temp->data;
            delete temp;
            size--;
            if(size == 0){
                tail = head;
            }
            return old;
        }
            //尾删
        E removeLast(){
            if(size==0){
                throw std::out_of_range("list is empty");
            }
            Node* current=head;
            while(current->next!=tail){
                current=current->next;
            }
            E old=tail->data;
            delete tail;
            tail=current;
            tail->next=nullptr;
            size--;
            return old;
        }
            //删除
        E remove(int index){
            checkIndexPosition(index);
            Node* current=head;
            for(int i=1;i<index;i++){
                current=current->next;
            }
            Node* temp=current->next;
            current->next=temp->next;
            E old=temp->data;
            delete temp;
            if(current->next==nullptr){
                tail=current;
            }
            size--;
            return old;
        }
        //改
        E set(int index,E e){
            checkIndexPosition(index);
            Node* current=head->next;
            for(int i=1;i<index;i++){
                current=current->next;
            }
            E old=current->data;
            current->data=e;
            return old;
        }
        //查
        E getE(int index){
            checkIndexPosition(index);
            Node* current=head->next;
            for(int i=1;i<index;i++){
                current=current->next;
            }
            return current->data;
        }
        int getSize(){
            return size;
        }
        Node* getHeadNext(){
            return head->next;
        }
        bool isEmpty(){
            return size==0;
        }
        void printLinklist(){
            Node* current=head->next;
            while(current!=nullptr){
                std::cout<<current->data;
                current=current->next;
            }
            std::cout<<std::endl;
        }
        //反转链表
        void reverse(){
            if(size<=1){
                return;
            }
            Node* prev=nullptr;
            Node* current=head->next;
            while(current!=nullptr){
                Node* next=current->next;
                current->next=prev;
                prev=current;
                current=next;
            }
            tail=head->next;
            head->next=prev;
        }
        //找中间位置,利用快慢指针
        E getMiddle(){
            if(size==0){
                throw std::out_of_range("list is empty");
            }
            Node* slow=head->next;
            Node* fast=head->next;
            while(fast->next!=nullptr&&fast->next->next!=nullptr){
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow->data;
        }
        //额外功能
        friend void addLinklist(Linklist<int>& L1, Linklist<int>& L2, Linklist<int>& result);
};