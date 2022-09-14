/*
*   Kyle Adrian del Castillo
*   BSCS II : CMSC 123 - C
*   10/21/2021
*/

#ifndef STACK_H
#define STACK_H

#include "node.h"

template <typename T>
class Stack{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Stack();
    ~Stack();

    int getSize() const;
    bool isEmpty() const;

    void setHead(Node<T> *someNode);
    void setTail(Node<T> *someNode);
    void updateSize(int amount);

    void push(T data);
    void pop();
    void peek() const;

    void printList();
};


/*
    Stack Constructor
    brief - Instantiated with type <T> (e.g: Stack<int> MyStack;)
    Params - None
    Return - Stack Object
*/
template <class T>
Stack<T>::Stack(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}


/*
    Stack Deconstructor
    brief - Creates a node pointing to head, loops through all nodes and deletes.
    Params - None
    Return - None
*/
template <class T>
Stack<T>::~Stack(){
    Node<T> *headNode = this->head;
    Node<T> *currentNode;

    for(int i=0; i < this->size; i++){
        currentNode = headNode;
        headNode = headNode->getNext();
        delete currentNode;
    }
}


template <class T>
int Stack<T>::getSize() const{
    return this->size;
}

template <class T>
bool Stack<T>::isEmpty() const{
    return this->size == 0;
}

template <class T>
void Stack<T>::setHead(Node<T> *someNode){
    this->head = someNode;
}

template <class T>
void Stack<T>::setTail(Node<T> *someNode){
    this->tail = someNode;
}

template <class T>
void Stack<T>::updateSize(int amount){
    this->size += amount;
}


/*
    Stack member function push()
    brief - accepts <T> type data and pushes it on top of the stack.
          - if stack empty, new node becomes tail and head, else node becomes head.

    Params - <T> data
    Return - None
*/
template <class T>
void Stack<T>::push(T data){
    Node<T> *newNode = new Node<T>(data);

    if( this->isEmpty() ){
        this->setHead( newNode );
        this->setTail( newNode );
    } else {
        newNode->setNext( this->head );
        this->setHead( newNode );
    }

    this->updateSize(1);
}


/*
    Stack member function pop()
    brief - removes the current head node of the stack. Node below becomes head.
          - if stack empty, prints out "stack is empty" and does nothing.

    Params - None
    Return - None
*/
template <class T>
void Stack<T>::pop(){
    Node<T> *extractedNode = this->head;

    if( this->isEmpty() ){
        std::cout << "\nstack empty.\n";
        return;
    }
    else if ( this->getSize() > 1 ) {
        this->setHead(extractedNode->getNext());
    }
    else {
        this->head = nullptr;
        this->tail = nullptr;
    }

    this->updateSize(-1);
    delete extractedNode;
}


/*
    Stack member function peek()
    brief - Shows data in head node.
          - if stack empty, prints out "stack is empty" and does nothing.

    Params - None
    Return - None (prints message)
*/
template <typename T>
void Stack<T>::peek() const{
    if( this->isEmpty() ){
        std::cout << "stack empty." << std::endl;
    }
    else {
        std::cout << this->head->getData() << std::endl;
    }
}


/*
    Stack member function printList()
    brief - Loops through all the nodes and prints Node -> data in array appearance.
          - creates an std::stringstream to collect all data for printing
          - if stack empty, prints out " [] " and does nothing

    Params - None
    Return - None (prints message)
*/
template <typename T>
void Stack<T>::printList(){
    if ( this->isEmpty() ) {
        std::cout << "[ ]" << std::endl;
        return;
    } else {
        Node<T> *currentNode = this->head;
        std::stringstream stack_elements("");
        stack_elements << "[ ";

        for ( int i=1; i < this->getSize(); i++ ) {
            stack_elements << currentNode->getData() << ", ";
            currentNode = currentNode->getNext();
        }
        stack_elements << currentNode->getData() << " ]";

        std::cout << stack_elements.str() << std::endl;
    }
}

#endif
