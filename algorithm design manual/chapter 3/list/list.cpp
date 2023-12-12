#include <iostream>

#include "list.h"

 List::~List(){
    Node * current = head;
    while(current){
        Node * buf = current;
        std::cout << "delete node: " << buf->data << std::endl;
        current = current->next;
        delete buf;
    }
}

List::List(char ** strs, int size){
    head = new Node {strs[0], nullptr};
    Node * current = head;
    for(int i = 1; i < size; ++i){
        current->next = new Node {strs[i], nullptr};
        current = current->next;
    }
}


void List::print(){  
    const Node * current = head;
    while (current != nullptr){
        std::cout << current->data;
        if(current->next != nullptr) std::cout << "->";
        current = current->next;
    }
    std::cout << std::endl;
}

// Linear complexity:  Theta(n)
Node * List::search(const char * target) const{
    Node * current = head;
    while(current != nullptr){
        if (current->data == target){
            return current;
        }
        current = current->next;
    }
    return current;
}

// Constant complexity: Theta(1)
 void List::insert(char * element){
    Node * p = new Node{element, head};
    head = p;
 }

// Linear complexity: Theta(n) 
 Node * List::predecessor(char * element){
    Node * current = head;
    // Border case: empty of one element list
    if ((current == nullptr) || (current->next == nullptr)){
        return nullptr;
    }
    while((current->next) != nullptr){
        if((current->next)->data == element){
            return current;
        }
        current = current->next;
    }
    return nullptr;
 }

 void List::erase(char * element){
    Node * element_to_delete = search(element);
    Node * predecessor_of_element_to_delete;
    if (element_to_delete != nullptr){
        predecessor_of_element_to_delete = predecessor(element);
        if (predecessor_of_element_to_delete == nullptr){
            head = element_to_delete->next;
        }
        else{
            predecessor_of_element_to_delete->next = element_to_delete->next;
        }
        delete element_to_delete;
    }
 }