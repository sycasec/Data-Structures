/*
*   Kyle Adrian del Castillo
*   BSCS II : CMSC 123 - C
*   10/21/2021
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>


template <class T>
class Node{

private:
    Node<T> *next;
    T data;

public:
    Node();
    Node(T data);

    void setNext(Node<T>* someNode);

    T getData() const;
    Node<T>* getNext() const;
};

/*
    Empty Node constructor
    brief - is not used in stack, here for testing
          - sets data and next to nullptr
*/
template <class T>
Node<T>::Node(){
    this->data = nullptr;
    this->next = nullptr;
}


/*
    Node default constructor
    brief - accepts <T> type data and sets own data to data param.
*/
template <class T>
Node<T>::Node(T data){
    this->data = data;
    this->next = nullptr;
}

template <class T>
void Node<T>::setNext(Node<T>* someNode){
    this->next = someNode;
}

template <class T>
T Node<T>::getData() const{
    return this->data;
}

template <class T>
Node<T>* Node<T>::getNext() const{
    return this->next;
}


#endif
