#include <iostream>
using namespace std;

class Node{
private:
    float value;
    Node *pNext = NULL;

public:
    Node(float value){
        this->value = value;
    } 

    ~Node(){};

    void setValue(float value){
        this->value = value;
    }

    void setpNext(Node *pNext){
        this->pNext = pNext;
    }

    float getVaulue(bool flag_print = false) const{
        if (flag_print == true)
            cout << "the value node = " << this->value << '\n';
        return this->value;
    }
    
    Node* getpNext(bool flag_print = false)const{
        if (flag_print == true)
            cout << "the address node = " << this->pNext << '\n';
        return this->pNext;
    }

};

class Queue{
private:
    Node *pHead = NULL;
    Node *pTail = NULL;
    int l = 0;
public:
    Queue(){};
    ~Queue(){};

    void push(float value){
        Node *p = new Node(value);
        if (this->pHead == NULL)
            this->pHead = this->pTail = p;
        else{
            this->pTail->setpNext(p);
            this->pTail = p;
        }
        this->l++;
    }

    float pop(){
        float last_value = INT64_MIN;
        if (this->pHead == NULL);
        else{
            Node *p = this->pHead;
            this->pHead = this->pHead->getpNext();
            delete p;
            this->l--;
        }
        return last_value;
    }

    int len()const{
        return this->l;
    }
    
    void transerve(){
        Node* p = this->pHead;
        while(p!=NULL){
            cout << " -> " << p->getVaulue();
            p = p->getpNext();
        }
        cout << '\n';
    }
};