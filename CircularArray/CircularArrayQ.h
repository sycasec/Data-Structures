/**
*   Kyle Adrian del Castillo
*   BSCS II :: CMSC 123 - C
*   initial commit: 10/30/2021
*   final commit:   11/14/2021
*/

#ifndef CIRCULARARRAYQ_H
#define CIRCULARARRAYQ_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

/**
*   Structs:    underflow and overflow exceptions
*   Brief:      halts execution and throws an error :: notifies with message
*/
struct underflow : public std::exception{
    const char * what () const throw () {
        return "\nQueue is empty!\n";
    }
};

struct overflow : public std::exception{
    const char * what () const throw () {
        return "\nQueue is full!\n";
    }
};

template <class T>
class CircularArrayQueue{
private:
    int front = 0;
    int rear = -1;
    int size = 0;
    T *CircularArray;
    int capacity;

public:
    CircularArrayQueue(int capacity);
    ~CircularArrayQueue();

    int getSize() const;
    bool isEmpty() const;
    bool isFull() const;

    void updateSize(int amount);
    void enqueue(T data);
    
    T dequeue();
    T peekFront() const;
    T peekRear() const;

    void printList() const;
    void printItem(T data) const;
};


/** CircularArrayQueue constructor
*   Brief:      Creates an array of type T and of size *capacity* (parameter)
*   Params:     int capacity
*/
template <class T>
CircularArrayQueue<T>::CircularArrayQueue(int capacity){
    CircularArray = new T[capacity];
    this->capacity = capacity;
}


/** CircularArrayQueue deconstructor
*   Brief:      deletes CircularArray
*   Params:     None
*/
template <class T>
CircularArrayQueue<T>::~CircularArrayQueue(){
    delete this->CircularArray;
}


/** int::getSize() const
*   Brief:      returns amount of items in array
*   Params:     None
*/
template <class T>
int CircularArrayQueue<T>::getSize() const{
    return this->size;
}


/** bool::isEmpty() const
*   Brief:      True if array is empty
*   Params:     None
*/
template <class T>
bool CircularArrayQueue<T>::isEmpty() const{
    return this->size == 0;
}


/** bool::isFull() const
*   Brief:      True if array is Full
*   Params:     None
*/
template <class T>
bool CircularArrayQueue<T>::isFull() const{
    return this->size == this->capacity;
}


/** void::updateSize()
*   Brief:      updates array size with amount
*   Params:     int::amount
*/
template <class T>
void CircularArrayQueue<T>::updateSize(int amount){
    this->size += amount;
}


/** void::Enqueue()
*   Brief:      Accepts data of type T, updates rear index and stores in CircularArray[rear]
*               throws overflow error if array is full (size/capacity = 0), moves rear index if necessary
*   Params:     <T> data
*/
template <class T>
void CircularArrayQueue<T>::enqueue(T data){
    if ( this->isFull() )
        throw overflow();

    this->rear += 1;
    if( this->rear == this->capacity )
        this->rear = 0;

    this->CircularArray[this->rear] = data;
    this->updateSize(1);

    std::cout << "[ " << data << " ] enqueued, Qstatus: " << this->getSize() << "/" << this->capacity << std::endl;
}


/** T :: Dequeue()
*   Brief:      Updates front index and extracts data from CircularArray[front - 1]
*               throws underflow error if array is empty (size = 0)
*   Params:     None
*/
template <class T>
T CircularArrayQueue<T>::dequeue(){
    if ( this->isEmpty() )
        throw underflow();

    this->front += 1;
    this->updateSize(-1);
    return this->CircularArray[this->front - 1];
}


/** T :: peekFront()
*   Brief:      returns data from array[front]
*               throws underflow if empty
*   Params:     None
*/
template <class T>
T CircularArrayQueue<T>::peekFront() const{
    if ( this->isEmpty() )
        throw underflow();

    return this->CircularArray[this->front];
}


/** T :: peekRear()
*   Brief:      returns data from array[rear]
*               throws underflow if empty
*   Params:     None
*/
template <class T>
T CircularArrayQueue<T>::peekRear() const{
    if ( this->isEmpty() )
        throw underflow();
        
    return this->CircularArray[this->rear];
}


/** fn::printList()
*   Brief:      Loops and prints data from CircularArray[0] -> CircularArray[capacity]
*               - prints "empty" indexes and "removed" data
*               - identifies *rear* with symbol 'r' and front with symbol 'f'
*
*   Params:     None
*/
template <class T>
void CircularArrayQueue<T>::printList() const{
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
*   Brief:      prints pop() or peek() data within brackets for highlighting
*   Params:     None
*/
template <class T>
void CircularArrayQueue<T>::printItem(T data) const{
    std::cout << "Value: [ " << data << " ]" << std::endl;
}

#endif
