/*
*   Kyle Adrian del Castillo
*   BSCS II : CMSC 123 - C
*   initial commit: 10/29/2021
8   final commit:   11/14/2021
*/

#ifndef DEQUE_H
#define DEQUE_H

#include "SLL.h"
#include <exception>


/**
*   Struct:    underflow exception
*   Brief:      halts execution and throws an error :: notifies with message
*/
struct DQunderflow : public std::exception{
    const char * what () const throw () {
        return "\nDeque is empty!\n";
    }
};

template <typename T>
class Dequeue{

private:
    SLL<T> *list;

public:
    Dequeue();

    bool DQempty() const;

    void enqueueBack(T data);
    void enqueueFront(T data);
    T dequeueBack();
    T dequeueFront();

    T front() const;
    T back() const;

    void printList();
    void printItem(T data) const;
};


/** Queue constructor
*   Brief:      creates a new SLL of type <T>
*   Params:     none
*/
template <typename T>
Dequeue<T>::Dequeue(){
    this->list = new SLL<T>();
}


/** fn bool::DQempty() const
*   Brief:      True if queue is empty
*   Params:     None
*/
template <typename T>
bool Dequeue<T>::DQempty() const{
    return this->list->isEmpty();
}


/** fn void::enqueueBack()
*   Brief:      Accepts data of type T, set as SLL->Tail
*               calls void :: SLL->pushBack()
*   Params:     <T> data
*/
template <typename T>
void Dequeue<T>::enqueueBack(T data){
    std::cout << "Enqueued Back [ " << data << " ] " << std::endl;
    this->list->pushBack(data);
}


/** fn void::enqueueFront()
*   Brief:      Accepts data of type T, set as SLL->head
*               calls void :: SLL->pushBack()
*   Params:     <T> data
*/
template <typename T>
void Dequeue<T>::enqueueFront(T data){
    std::cout << "Enqueued Front [ " << data << " ] " << std::endl;
    this->list->pushFront(data);
}


/** fn T :: dequeueBack()
*   Brief:      Extracts data from and deletes SLL->tail 
*               calls T :: SLL->popBack() 
*               throws underflow error if array is empty (size = 0)
*   Params:     None
*/
template <typename T>
T Dequeue<T>::dequeueBack(){
    if ( this->DQempty() )
        throw DQunderflow();

    return this->list->popBack();
}


/** fn T :: dequeueFront()
*   Brief:      Extracts data from and deletes SLL->head
*               calls T :: SLL->popFront() 
*               throws DQunderflow error if array is empty (size = 0)
*   Params:     None
*/
template <typename T>
T Dequeue<T>::dequeueFront(){
    if ( this->DQempty() )
        throw DQunderflow();

    return this->list->popFront();
}


/** T :: Front()
*   Brief:      returns data from SLL->head
*               calls T :: SLL->peek()
*   Params:     None
*/
template <typename T>
T Dequeue<T>::front() const{
    if ( this->DQempty() )
        throw DQunderflow();

    return this->list->peekFront();
}


/** T :: Back()
*   Brief:      returns data from SLL->head
*               calls T :: SLL->peekBack()
*   Params:     None
*/
template <typename T>
T Dequeue<T>::back() const{
    if ( this->DQempty() )
        throw DQunderflow();

    return this->list->peekBack();
}


/** fn void::printList()
*   Brief:      Loops and prints data from SLL->head to SLL->tail
*               calls SLL->printList()
*
*   Params:     None
*/
template <typename T>
void Dequeue<T>::printList(){
    this->list->printList();
}


/** fn::printItem()
*   Brief:      prints pop() or peek() data within brackets
*               calls SLL->printItem()
*   Params:     None
*/
template <typename T>
void Dequeue<T>::printItem(T data) const{
    this->list->printItem(data);
}


#endif
