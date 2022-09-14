#include "stack.h"
#define NONE 600009

template <typename T>
Node::Node(T data){
    this->data = data;
    this->next = nullptr;
}

template <typename T>
void Node::setNext(Node* someNode){
    this->next = someNode;
}

template <typename T>
T Node::getData() const{
    return this->data;
}

template <typename T>
Node* Node::getNext() const{
    return this->next;
}

template <typename T>
Stack::Stack(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <typename T>
Node* Stack::getNode(int index){
    Node* currentNode = this->head;
    for ( int i=0; i < index; i++ ) {
        currentNode = currentNode->getNext();
    }
    return currentNode;
}

template <typename T>
int Stack::getSize() const{
    return this->size;
}

template <typename T>
bool Stack::isEmpty() const{
    return this->getSize() == 0;
}

template <typename T>
void Stack::setHead(Node *someNode){
    this->head = someNode;
}

template <typename T>
void Stack::setTail(Node *someNode){
    this->tail = someNode;
}

template <typename T>
void Stack::updateSize(int amount){
    this->size += amount;
}

template <typename T>
void Stack::pop(){
    Node* extractedNode = this->head;

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

template <typename T>
void Stack::push(T data){
    Node* newNode = new Node(data);

    if( this->isEmpty() ){
        this->setHead( newNode );
        this->setTail( newNode );
    } else {
        newNode->setNext( this->head );
        this->setHead( newNode ); 
    }

    this->updateSize(1);
}

template <typename T>
void Stack::peek(){
    if( this->isEmpty() ){
        std::cout << "\nstack empty.\n";
    } 
    else {
        std::cout << this->head->getData() << std::endl;
    }
}

template <typename T>
void Stack::printList(){
    Node* currentNode = this->head;
    std::stringstream stack_elements("");
    stack_elements << "\n" << "[ ";

    for ( int i=1; i < this->getSize(); i++ ) {
        stack_elements << currentNode->getData() << ", ";
        currentNode = currentNode->getNext();
    }
    stack_elements << currentNode->getData() << " ]\n";

    std::cout << stack_elements.str();
}