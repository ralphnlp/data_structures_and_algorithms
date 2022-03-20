#include<iostream>
using namespace std;

class Node{
private:
    float value;
    int no = 0;
    Node *pLeft = NULL;
    Node *pRight = NULL;
public:
    Node(float value){
        this->value = value;
        this->no ++;
    }
    ~Node(){}

    void set_value(float value){
        this->value = value;
    }
    void set_no(int no){
        this->no = no;
    }
    void set_pLeft(Node *p){
        this->pLeft = p;
    }
    void set_pRight(Node *p){
        this->pRight = p;
    }

    float get_value()const{
        return this->value;
    }
    int get_no()const{
        return this->no;
    }
    Node* get_pLeft()const{
        return this->pLeft;
    }
    Node* get_pRight()const{
        return this->pRight;
    }
};


class Binary_Tree{
private:
    Node *pRoot = NULL;
public:
    Binary_Tree(){};
    ~Binary_Tree(){};

    void addNode(float value){
        Node *p = new Node(value);
        if (this->pRoot == NULL)
            this->pRoot = p;
        else{
            Node *current_node = this->pRoot;
            while(true){
                if (p->get_value() == current_node->get_value()){
                    int no = current_node->get_no();
                    current_node->set_no(no+1);
                    break;
                }

                if (p->get_value() < current_node->get_value()){
                    if (current_node->get_pLeft() == NULL){
                        current_node->set_pLeft(p);
                        break;
                    }
                    else
                        current_node = current_node->get_pLeft();
                }

                if (p->get_value() > current_node->get_value()){
                    if (current_node->get_pRight() == NULL){
                        current_node->set_pRight(p);
                        break;
                    }
                    else
                        current_node = current_node->get_pRight();
                }
            }
        }
    }

    Node *getRoot()const{
        return this->pRoot;
    }

    void NLR(Node* current_node){
        if (current_node != NULL){
            cout << current_node->get_value() << '\t' << current_node->get_no() << '\n';
            NLR(current_node->get_pLeft());
            NLR(current_node->get_pRight());
        }
    };

};