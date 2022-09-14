#include "DLL.h"
#define INDEX_ERROR 600009

Node::Node(int data){
    this->data = data;
    this->next = nullptr;
    this->previous = nullptr;
}

void Node::setNext(Node* someNode){
    this->next = someNode;
}

void Node::setPrevious(Node* someNode){
    this->previous = someNode;
}

int Node::getData() const{
    return this->data;
}

Node* Node::getNext() const{
    return this->next;
}

Node* Node::getPrevious() const{
    return this->previous;
}



DLL::DLL(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

Node* DLL::getNode(int index){
    Node* currentNode = this->head;
    for ( int i=0; i < index; i++ ) {
        currentNode = currentNode->getNext();
    }
    return currentNode;
}

int DLL::getSize() const{
    return this->size;
}

void DLL::setHead(Node *someNode){
    this->head = someNode;
}

void DLL::setTail(Node *someNode){
    this->tail = someNode;
}

void DLL::updateSize(int amount){
    this->size += amount;
}

int DLL::pop(int index) {
    Node* extractedNode;

    if ( index >= 0 && index <= this->getSize() - 1 ){
        if ( index == 0 ){
            extractedNode = this->head;
            this->setHead( extractedNode->getNext() );
        }
        else {
            Node* previousNode = this->getNode(index - 1);
            extractedNode = previousNode->getNext();
            previousNode->setNext( extractedNode->getNext() );

            if ( index == this->getSize() )
                this->setTail( previousNode );
        }
    }
    else {
        if(this->getSize() == 0)
            return INDEX_ERROR;

        Node* extractedNode = this->tail;
        if (this->getSize() == 2){
            Node* previousNode = extractedNode->getPrevious();
            this->setTail( previousNode );
        } else if ( this->getSize() == 1) {
            this->setHead( nullptr );
            this->setTail( nullptr );
        }

    }
    int extracted_data = extractedNode->getData();
    delete extractedNode;
    this->updateSize(-1);

    return extracted_data;
}

int DLL::decapitate(){
    Node* extractedNode = this->head;
    this->setHead( extractedNode->getNext() );
    int extracted_data = extractedNode->getData();
    delete extractedNode;
    this->updateSize(-1);

    return extracted_data;
}

void DLL::push(int data){
    Node* newNode = new Node(data);
    newNode->setNext( this->head );
    if( this->getSize() == 0 )
        this->setTail( newNode );

    this->setHead( newNode );
    this->updateSize(1);
}

void DLL::insert(int data, int index){
    if ( index >= 0 && index <= this->size ) {

        Node* newNode = new Node(data);

        if ( index == 0 ) { //basically push()
            newNode->setNext( this->head );
            this->setHead( newNode );
        }

        if ( index == this->getSize() ) { //basically append
            if ( this->tail != nullptr )
                this->tail->setNext( newNode );  
            this->setTail( newNode );
        }

        if ( index > 0 && index < this->getSize() ) {
            Node *previousNode = this->getNode( index - 1 );
            newNode->setNext( previousNode->getNext() );
            previousNode->setNext( newNode );
        } 

        this->updateSize(1);
    }
}

void DLL::append(int data){
    Node* newNode = new Node(data);
    if( this->tail != nullptr )
        this->tail->setNext( newNode );
    if( this->getSize() == 0)
        this->setHead( newNode );

    this->setTail( newNode );
    this->updateSize(1);
}

void DLL::printList(){
    Node* currentNode = this->head;
    std::stringstream list_elements("");
    list_elements << "\n" << "[ ";

    for ( int i=1; i < this->getSize(); i++ ) {
        list_elements << currentNode->getData() << ", ";
        currentNode = currentNode->getNext();
    }
    list_elements << currentNode->getData() << " ]\n";

    std::cout << list_elements.str();
}