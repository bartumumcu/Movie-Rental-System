#ifndef LLIST_H
#define LLIST_H
#include <iostream>
#include "Node.h"
using namespace std;
//BARTU MUMCU SEC:2 22103523
template<class ItemType>
class LinkedList{

    public:
    Node<ItemType>* headPtr;
    int itemCount=0;

    
    LinkedList(Node<ItemType>* head){
        headPtr =head;
        itemCount=1;
    }
    LinkedList(){
        headPtr=nullptr;
        itemCount=0;
    }
    
    Node<ItemType>* getNode(int position) const {
        // if(position<1 && position>itemCount){
        //     //ERROR
        // }
        
            Node<ItemType>* curPtr=headPtr;
            for(int i=1;i<position;i++)
            curPtr=curPtr->getNext();

            return curPtr;
        
    }

    

    void sortedInsert(Node<ItemType>* &headPtr,ItemType newItem){
        if ((headPtr == nullptr) || (newItem < headPtr->item)){
            
    Node<ItemType>* newPtr =new Node<ItemType>;
    
    newPtr->item = newItem;
    
    newPtr->next = headPtr;
    
    headPtr = newPtr;
    itemCount++;
    }
    else{
    sortedInsert(headPtr->next, newItem);
   }
 }

void remove(int position){
    Node<ItemType>* curPtr;
    if(position==1){
        curPtr=headPtr;
        headPtr=headPtr->next;
    }
    else{   //MEMORY LEAK
        Node<ItemType>* prevPtr=getNode(position-1);
        curPtr=prevPtr->next;
        prevPtr->setNext(curPtr->next);
    }
    curPtr->setNext(nullptr);
    delete curPtr;
    curPtr=nullptr;
    itemCount--;
}
void clear(){
    while(itemCount>0){
        remove(1);
    }
}


};
#endif