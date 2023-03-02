#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
//BARTU MUMCU SEC:2 22103523
template<class ItemType>
class Node{
    
   public:
    ItemType item;
    Node<ItemType>* next;

    Node(ItemType anItem){
        item=anItem;
        next=nullptr;
    }
    
    Node(){
        next=nullptr;
        
    }

    Node<ItemType>* getNext(){
        return next;
    }
    
    void setItem(const ItemType& anItem){
        this->item=anItem;
    }
    void setNext(Node<ItemType>* nextNodePtr){
        this->next=nextNodePtr;
    }
    

};
#endif