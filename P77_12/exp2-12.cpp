#include "linklist.cpp"
#include <string>
//字符串转链表
void stringToLinklist(const std::string& str,Linklist<int>& L){
    for(char c:str){
        if(!std::isdigit(c)){
            throw std::invalid_argument("input string contains non-digit characters");
        }
        int num=c-'0';
        L.addLast(num);
    }
}
//相加
void addLinklist(Linklist<int>& L1, Linklist<int>& L2, Linklist<int>& result){
    L1.reverse();
    L2.reverse();
    int carry=0;
    auto p1=L1.getHeadNext();
    auto p2=L2.getHeadNext();
    while(p1!=nullptr||p2!=nullptr||carry!=0){
        int x=p1!=nullptr?p1->data:0;
        int y=p2!=nullptr?p2->data:0;
        int sum=carry+x+y;
        carry=sum/10;
        result.addFirst(sum%10);
        if(p1!=nullptr){
            p1=p1->next;
        }
        if(p2!=nullptr){
            p2=p2->next;
        }
    }
    L1.reverse();
    L2.reverse();
}

int main(){
    Linklist<int> L1;
    Linklist<int> L2;
    std::string s1;
    std::cout<<"write the first number string: ";
    std::cin>>s1;
    std::cout<<"write the second number string: ";
    std::string s2;
    std::cin>>s2;
    stringToLinklist(s1, L1);
    stringToLinklist(s2, L2);
    Linklist<int> result;
    addLinklist(L1, L2, result);
    std::cout<<"result: ";
    result.printLinklist();
    std::cout<<"middle of result: "<<result.getMiddle()<<std::endl;
    return 0;
}