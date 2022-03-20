#include <iostream>
#include "linked_list.h"
using namespace std;

class HashTable{
private:
    LinkedList table[10];
    int hasing(float value){
        int key = int(value)%10;
        return key;
    }

public:
    HashTable(){};
    ~HashTable(){};

    void add_values(float value){
        int key = this->hasing(value);
        this->table[key].addNode(value);
    }

    void printTable(){
        for(int i=0; i<10; i++){
            cout << "the_key[" << i << "]";
            this->table[i].transerve();
        }
    }
};
