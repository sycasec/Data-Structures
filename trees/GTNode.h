/*
*   Kyle Adrian del Castillo
*   BSCS II : CMSC 123 - C
*
*   initial commit: 11/26/2021   
*   final commit:   11/30/2021
*/

#ifndef GTNODE_H
#define GTNODE_H

#include "sll.h"

template <class T>
class GeneralTreeNode{

private:
    T data;
    GeneralTreeNode<T>* parent;

public:
    SLL<GeneralTreeNode<T>*> children;

    GeneralTreeNode();
    GeneralTreeNode(T data);

    void setParent(GeneralTreeNode<T>* parentNode);
    void addChild(GeneralTreeNode<T>* childNode);
    void setData(T data);

    T getData() const;
    GeneralTreeNode<T>* getParent() const;
};


/*
    GeneralTreeNode default constructor
    brief - instantiate an empty node
          - sets parent to nullptr
*/
template <class T>
GeneralTreeNode<T>::GeneralTreeNode() {
    this->parent = nullptr;
}


/*
    GeneralTreeNode constructor with Data
    brief - accepts <T> type data and sets own data to data arg.
*/
template <class T>
GeneralTreeNode<T>::GeneralTreeNode(T data) {
    this->parent = nullptr;
    this->data = data;
}


/** fn void :: setParent(parentNode)
 *  brief :     sets this->parent = parentNode
 *  params:     GeneralTreeNode<T>* parentNode
 */
template <class T>
void GeneralTreeNode<T>::setParent(GeneralTreeNode<T>* parentNode) {
    this->parent = parentNode;
}


/** fn void :: addChildren(childNode)
 *  brief :     pushes childNode to this->children (list of children)
 *  params:     GeneralTreeNode<T>* childNode
 */
template <class T>
void GeneralTreeNode<T>::addChild(GeneralTreeNode<T>* childNode) {
    childNode->setParent(this);
    this->children.pushBack(childNode);
}


/** fn void :: setData(T data)
 *  brief :     sets data to passed argument
 *  params:     T data (same type as instantiation)
 */
template <class T>
void GeneralTreeNode<T>::setData(T data) {
    this->data = data;
}

/** fn T :: getData()
 *  brief :     returns data stored in node
 *  params:     none
 */
template <class T>
T GeneralTreeNode<T>::getData() const {
    return this->data;
}

/** fn GeneralTreeNode<T>* :: getParent()
 *  brief :     returns pointer to parent of node
 *  params:     none
 */
template <class T>
GeneralTreeNode<T>* GeneralTreeNode<T>::getParent() const {
    return this->parent;
}

#endif