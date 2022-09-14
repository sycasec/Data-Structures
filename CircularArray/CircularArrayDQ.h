/**
*   Kyle Adrian del Castillo
*   BSCS II :: CMSC 123 - C
*   initial commit: 11/1/2021
*   final commit: 11/14/2021
*/

#ifndef CIRCULARARRAYDQ_H
#define CIRCULARARRAYDQ_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

/**
*   Structs:    DQunderflow and DQoverflow exceptions
*   Brief:      halts execution and throws an error :: notifies with message
*/
struct DQunderflow : public std::exception{
    const char * what () const throw () {
        return "\nQueue is empty!\n";
    }
};

struct DQoverflow : public std::exception{
    const char * what () const throw () {
        return "\nQueue is full!\n";
    }
};


template <class T>
class CircularArrayDeque{
private:
    int front = 0;
    int rear = -1;
    int size = 0;
    T *CircularArray;
    int capacity;

public:
    CircularArrayDeque(int capacity);
    ~CircularArrayDeque();

    int getSize() const;
    bool isEmpty() const;
    bool isFull() const;

    void updateSize(int amount);
    void EnqueueFront(T data);
    void EnqueueBack(T data);

    T DequeueFront();
    T DequeueRear();

    T peekFront() const;
    T peekRear() const;

    void printList() const;
    void printItem(T data) const;
};


/** CircularArrayDeque constructor
*   Brief:      Creates an array of type T and of size *capacity* (parameter)
*   Params:     int capacity
*/
template <class T>
CircularArrayDeque<T>::CircularArrayDeque(int capacity){
    CircularArray = new T[capacity];
    this->capacity = capacity;
}


/** CircularArrayDeque deconstructor
*   Brief:      deletes CircularArray
*   Params:     None
*/
template <class T>
CircularArrayDeque<T>::~CircularArrayDeque(){
    delete this->CircularArray;
}

/** i
 * nt::getSize() const
*   Brief:      returns amount of items in array
*   Params:     None
*/
template <class T>
int CircularArrayDeque<T>::getSize() const{
    return this->size;
}


/** bool::isEmpty() const
*   Brief:      True if array is empty
*   Params:     None
*/
template <class T>
bool CircularArrayDeque<T>::isEmpty() const{
    return this->size == 0;
}


/** bool::isFull() const
*   Brief:      True if array is Full
*   Params:     None
*/
template <class T>
bool CircularArrayDeque<T>::isFull() const{
    return this->size == this->capacity;
}


/** void::updateSize()
*   Brief:      updates array size with amount
*   Params:     int::amount
*/
template <class T>
void CircularArrayDeque<T>::updateSize(int amount){
    this->size += amount;
}


/** void::EnqueueBack()
*   Brief:      Accepts data of type T, updates rear index and stores in CircularArray[rear]
*               throws DQoverflow error if array is full (size/capacity = 0), moves rear index if necessary
*   Params:     <T> data
*/
template <class T>
void CircularArrayDeque<T>::EnqueueBack(T data){
    if ( this->isFull() )
        throw DQoverflow();

    this->rear += 1;
    if( this->rear == this->capacity )
        this->rear = 0;

    this->CircularArray[this->rear] = data;
    this->updateSize(1);

    std::cout << "[ " << data << " ] enqueued back, DQstatus: " << this->getSize() << "/" << this->capacity << std::endl;
}


/** void::EnqueueFront()
*   Brief:      Accepts data of type T, updates front index and stores in CircularArray[front]
*               throws DQoverflow error if array is full (size/capacity = 0), moves front index if necessary
*   Params:     <T> data
*/

template <class T>
void CircularArrayDeque<T>::EnqueueFront(T data){
    if ( this->isFull() )
        throw DQoverflow();
    
    if( this->front == 0 ){
        this->front = this->capacity - 1;
    } else {
        this->front -= 1;
    }

    this->CircularArray[this->front] = data;
    this->updateSize(1);

    std::cout << "[ " << data << " ] enqueued front, DQstatus: " << this->getSize() << "/" << this->capacity << std::endl;
} 
/** T :: DequeueFront()
*   Brief:      Updates front index and extracts data from CircularArray[front - 1]
*               throws DQunderflow error if array is empty (size = 0)
*   Params:     None
*/
template <class T>
T CircularArrayDeque<T>::DequeueFront(){
    if ( this->isEmpty() )
        throw DQunderflow();

    this->updateSize(-1);

    if ( this->front == this->capacity - 1){
        this->front = 0;
        return this->CircularArray[this->capacity - 1];
    } else {
        this->front += 1;
        return this->CircularArray[this->front - 1];
    }
    
    
}

/** T :: DequeueFront()
*   Brief:      Updates rear index and extracts data from CircularArray[rear + 1]
*               throws DQunderflow error if array is empty (size = 0)
*   Params:     None
*/
template <class T>
T CircularArrayDeque<T>::DequeueRear(){
    if ( this->isEmpty() )
        throw DQunderflow();

    this->updateSize(-1);

    if ( this->rear == 0 ){
        this->rear = this->capacity - 1;
        return this->CircularArray[0];
    } else {    
        this->rear -= 1;
        return this->CircularArray[this->rear + 1];
    }
}

template <class T>
T CircularArrayDeque<T>::peekFront() const{
    return this->CircularArray[this->front];
}

template <class T>
T CircularArrayDeque<T>::peekRear() const{
    return this->CircularArray[this->rear];
}

/** void::printList()
*   Brief:      Loops and prints data from CircularArray[0] -> CircularArray[capacity]
*               - prints "empty" indexes and "removed" data
*               - identifies *rear* with symbol 'r' and front with symbol 'f'
*
*   Params:     None
*/
template <class T>
void CircularArrayDeque<T>::printList() const{
    std::cout << "[ ";
    for (int i=0; i < this->capacity; i++){
        if (i == this->front)
            std::cout << 'f';
        if (i == this->rear)
            std::cout << 'r';
        if (i == this->capacity - 1){
            std::cout << this->CircularArray[i] << " ]" << std::endl;
            return;
        }

        std::cout << this->CircularArray[i] << ", ";
    }
}


/** fn::printItem()
*   Brief:      for printing pop() or peek() data within brackets for highlighting
*   Params:     None
*/
template <class T>
void CircularArrayDeque<T>::printItem(T data) const{
    std::cout << "Value: [ " << data << " ]" << std::endl;
}

#endif
