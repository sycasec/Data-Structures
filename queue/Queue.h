/*
*   Kyle Adrian del Castillo
*   BSCS II : CMSC 123 - C
*   10/21/2021
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "SLL.h"
#include <exception>


/**
*   Struct:    underflow exception
*   Brief:      halts execution and throws an error :: notifies with message
*/
struct underflow : public std::exception{
    const char * what () const throw () {
        return "\nQueue is empty!\n";
    }
};

template <typename T>
class Queue{

private:
    SLL<T> list;

public:
    Queue();

    bool Qempty() const;

    void enqueue(T data);
    T dequeue();
    T front() const;

    void printList();
    void printItem(T data) const;
};


/** Queue constructor
*   Brief:      creates a new SLL of type <T>
*   Params:     none
*/
template <typename T>
Queue<T>::Queue(){
}


/** fn bool::Qempty() const
*   Brief:      True if queue is empty
*   Params:     None
*/
template <typename T>
bool Queue<T>::Qempty() const{
    return this->list.isEmpty();
}


/** fn void::Enqueue()
*   Brief:      Accepts data of type T, set as SLL->tail
*               calls void :: SLL->pushBack()
*   Params:     <T> data
*/
template <typename T>
void Queue<T>::enqueue(T data){
    std::cout << "Enqueued Data [ " << data << " ] " << std::endl;
    this->list.pushBack(data);
}


/** fn T :: Dequeue()
*   Brief:      Extracts data from and deletes SLL->head 
*               calls T :: SLL->popFront() 
*               throws underflow error if array is empty (size = 0)
*   Params:     None
*/
template <typename T>
T Queue<T>::dequeue(){
    if ( this->Qempty() )
        throw underflow();

    return this->list.popFront();
}


/** fn T :: Front()
*   Brief:      returns data from SLL->head
*               calls T :: SLL->peek()
*   Params:     None
*/
template <typename T>
T Queue<T>::front() const{
    if ( this->Qempty() )
        throw underflow();

    return this->list.peekFront();
}

/** fn void::printList()
*   Brief:      Loops and prints data from SLL->head to SLL->tail
*               calls SLL->printList() 
*
*   Params:     None
*/
template <typename T>
void Queue<T>::printList(){
    this->list.printList();
}

/** fn::printItem()
*   Brief:      prints pop() or peek() data within brackets
*               calls SLL->printItem
*   Params:     None
*/
template <typename T>
void Queue<T>::printItem(T data) const{
    this->list.printItem(data);
}


#endif
