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

class Stack{
private:
    Node *pHead = NULL;
    Node *pTail = NULL;
    int l = 0;
public:
    Stack(){};
    ~Stack(){};

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
            last_value = this->pTail->getVaulue();
            if (this->pHead == this->pTail){
                delete this->pTail;
                this->pHead = this->pTail = NULL;
            }
            else{
                Node *p = this->pHead;
                while(p->getpNext() != this->pTail)
                    p = p->getpNext();
                delete p->getpNext();
                this->pTail = p;
            }
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