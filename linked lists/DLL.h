#ifndef DLL_H
#define DLL_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

class Node{
private:
    int data;
    Node* next;
    Node* previous;

public:
    Node(int data);

    void setNext(Node* someNode);
    void setPrevious(Node* someNode); 
    
    int getData() const;
    Node* getNext() const;
    Node* getPrevious() const; 
};


class DLL{
private:
    Node *head;
    Node *tail;
    int size;

public:
    DLL();
    // implement previous functinality
    Node* getNode(int index);

    int getSize() const;

    void setHead(Node *someNode);
    void setTail(Node *someNode);
    void updateSize(int amount);

    int pop(int index);
    int decapitate();
    void push(int data);
    void insert(int data, int index);
    void append(int data);

    void printList();
};


#endif