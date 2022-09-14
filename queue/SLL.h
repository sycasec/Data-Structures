/*
*   Kyle Adrian del Castillo
*   BSCS II : CMSC 123 - C

*   initial commit: 10/29/2021
*   final commit:   11/14/2021
*/

#ifndef SLL_H
#define SLL_H

#include "node.h"

template <typename T>
class SLL{

private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    SLL();
    ~SLL();

    int getSize() const;
    bool isEmpty() const;
    Node<T>* getNode(int index);

    void setHead(Node<T> *someNode);
    void setTail(Node<T> *someNode);
    void updateSize(int amount);

    void pushBack(T data);
    void pushFront(T data);
    T popFront();
    T popBack();

    T peekFront() const;
    T peekBack() const;

    void printList();
    void printItem(T data) const;
};

// SLL is an abbreviation of Singly Linked List

/** SLL constructor
*   Brief:      creates a new SLL of type <T>
*   Params:     none
*/
template <typename T>
SLL<T>::SLL(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}


/** SLL deconstructor
*   Brief:      loops from SLL->head to SLL->tail and deletes nodes.
*   Params:     none
*/
template <typename T>
SLL<T>::~SLL(){
    Node<T> *headNode = this->head;
    Node<T> *currentNode;

    for(int i=0; i < this->size; i++){
        currentNode = headNode;
        headNode = headNode->getNext();
        delete currentNode;
    }
}


/** fn int::getSize() const
 *  Brief:      returns SLL->size
 *  Params:     None
 */
template <typename T>
int SLL<T>::getSize() const{
    return this->size;
}


/** fn bool::isEmpty() const
 *  Brief:      True if SLL is empty
 *  Params:     None
 */
template <typename T>
bool SLL<T>::isEmpty() const{
    return this->size == 0;
}


/** fn Node<T>::getNode()
 *  Brief:      Loops through SLL->head to SLL->tail
 *              and searches for Node with specified index
 * 
 *  constraint: if index > SLL->size, does nothing
 * 
 *  Params:     int index
 */
template <typename T>
Node<T>* SLL<T>::getNode(int index){
    Node<T>* currentNode = this->head;
    for(int i=0; i < index - 1; i++)
        currentNode = currentNode->getNext();

    return currentNode;
}


/** fn void::setHead() 
 *  Brief:      set specified Node pointer as SLL->head
 *  Params:     Node<T> *someNode
 */
template <typename T>
void SLL<T>::setHead(Node<T> *someNode){
    this->head = someNode;
}


/** fn void::setTail() 
 *  Brief:      set specified Node pointer as SLL->tail
 *  Params:     Node<T> *someNode
 */
template <typename T>
void SLL<T>::setTail(Node<T> *someNode){
    this->tail = someNode;
}


/** fn void::updateSize() 
 *  Brief:      update size based on specified amount
 *  Params:     int amount
 */
template <typename T>
void SLL<T>::updateSize(int amount){
    this->size += amount;
}


/** fn void::pushBack() 
 *  Brief:      creates new Node<T> with value=(data)
 *              if: list is empty, new Node set as Head and Tail
 *              else: new Node set as tail             
 * 
 *  Params:     <T> data
 */
template <typename T>
void SLL<T>::pushBack(T data){
    Node<T> *newNode = new Node<T>(data);

    if( this->isEmpty() ){
        this->setHead( newNode );
        this->setTail( newNode );
    } else {
        this->tail->setNext( newNode );
        this->setTail( newNode );
    }

    this->updateSize(1);
}


/** fn void::pushFront() 
 *  Brief:      creates new Node<T> with value=(data)
 *              if: list is empty, new Node set as Head and Tail
 *              else: new Node set as head             
 * 
 *  Params:     <T> data
 */
template <typename T>
void SLL<T>::pushFront(T data){
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


/** fn void::pushFront() 
 *  Brief:      extracts value of SLL->head
 *              if SLL->size > 1: SLL->head = extractedNode->next  
 *              else: head && tail = nullptr (list empty)            
 * 
 *  Params:     <T> data
 */
template <typename T>
T SLL<T>::popFront(){
    Node<T> *extractedNode = this->head;
    T data = extractedNode->getData();

    if ( this->getSize() > 1 ) {
        this->setHead(extractedNode->getNext());
    }
    else {
        this->head = nullptr;
        this->tail = nullptr;
    }

    delete extractedNode;
    this->updateSize(-1);
    return data;
}

/** fn void::pushFront() 
 *  Brief:      extracts value of SLL->tail
 *              if SLL->size > 1: SLL->tail = extractedNode->prevNode 
 *                       ( previous node acquired through getNode() )
 *              else: head && tail = nullptr (list empty)            
 * 
 *  Params:     <T> data
 */ 
template <typename T>
T SLL<T>::popBack(){
    Node<T> *extractedNode = this->tail;
    T data = extractedNode->getData();
    
    if ( this->getSize() > 1 ) {
        this->setTail( this->getNode( this->getSize()-1));
        this->tail->setNext(nullptr);
    }
    else {
        this->head = nullptr;
        this->tail = nullptr;
    }

    delete extractedNode;
    this->updateSize(-1);
    return data;
}


/** fn T :: peekFront()
*   Brief:      returns data from SLL->head
*               calls T :: Node->getData()
*   Params:     None
*/
template <typename T>
T SLL<T>::peekFront() const{
    Node<T> *frontNode = this->head;
    return frontNode->getData();
}


/** fn T :: peekBack()
*   Brief:      returns data from SLL->tail
*               calls T :: Node->getData()
*   Params:     None
*/
template <typename T>
T SLL<T>::peekBack() const{
    Node<T> *backNode = this->tail;
    return backNode->getData();
}


/** fn void::printList()
*   Brief:      Loops and prints data from SLL->head to SLL->tail
*               creates std::stringstream and adds all list elements
*               prints list elements with brackets at loop end
*
*   Params:     None
*/
template <typename T>
void SLL<T>::printList(){
    if ( this->isEmpty() ) {
        std::cout << "[ ]" << std::endl;
        return;
    } else {
        Node<T> *currentNode = this->head;
        std::stringstream listElements("");
        listElements << "[ ";

        for ( int i=1; i < this->getSize(); i++ ) {
            listElements << currentNode->getData() << ", ";
            currentNode = currentNode->getNext();
        }
        listElements << currentNode->getData() << " ]";

        std::cout << listElements.str() << std::endl;
    }
}

/** fn::printItem()
*   Brief:      prints pop() or peek() data within brackets for highlighting
*   Params:     None
*/
template <class T>
void SLL<T>::printItem(T data) const{
    std::cout << "Value: [ " << data << " ]" << std::endl;
}

#endif