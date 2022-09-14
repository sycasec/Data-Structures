/*
*   Kyle Adrian del Castillo
*   BSCS II : CMSC 123 - C
*
*   initial commit: 11/26/2021   
*   final commit:   11/30/2021
*/

#ifndef GENERALTREE_H
#define GENERALTREE_H

#include "queue.h"
#include "GTNode.h"

template <class T>
class GeneralTree{
private:
    GeneralTreeNode<T> *rootNode;
    
public:
    GeneralTree();
    GeneralTree(GeneralTreeNode<T>* root);
    ~GeneralTree();

    void setRoot(GeneralTreeNode<T>* root);
    GeneralTreeNode<T>* getRoot() const;

    void BreadthFirst();
};


/*
    General Tree default constructor
    brief:  sets rootNode to nullptr
*/
template <class T>
GeneralTree<T>::GeneralTree(){
    this->rootNode = nullptr;
}

/*
    General Tree with rootNode constructor
    brief:  sets rootNode to passed argument GeneralTreeNode<T>* root
*/
template <class T>
GeneralTree<T>::GeneralTree(GeneralTreeNode<T>* root){
    this->rootNode = root;
}

/**
 *  Tree deconstructor
 *  brief:  deletes root node
 */
template <class T>
GeneralTree<T>::~GeneralTree(){
    delete this->rootNode;
}


/** fn void :: setRoot()
 *  brief :     sets this->rootNode = root
 *  params:     GeneralTreeNode<T>* root
 */
template <class T>
void GeneralTree<T>::setRoot(GeneralTreeNode<T>* root) {
    this->rootNode = root;
}

/** fn GeneralTreeNode<T>* :: getRoot()
 *  brief :     returns a pointer to this->rootNode
 *  params:     none
 */
template <class T>
GeneralTreeNode<T>* GeneralTree<T>::getRoot() const {
    return this->rootNode;
}

/**
 *  fn void :: BreadthFirst() 
 *  brief:      Breadth-First traversal of tree starting from this->rootNode
 *  params:     None
 */
template <class T>
void GeneralTree<T>::BreadthFirst() {
    std::cout << "[ ";
    Queue<GeneralTreeNode<T>*> queue;
    queue.enqueue(this->rootNode);  

    while ( !queue.Qempty() ) {
        GeneralTreeNode<T>* currentNode = queue.dequeue();
        std::cout << currentNode->getData();
        
        if( !currentNode->children.isEmpty() ){

            int maxChildren = currentNode->children.getSize();
            Node<GeneralTreeNode<T>*>* curr = currentNode->children.getHead();

            for(int i=0; i < maxChildren; i++){
                queue.enqueue( curr->getData() );
                curr = curr->getNext();
            }
        }

        if ( !queue.Qempty() ) { std::cout << ", "; }
    }

    std::cout << " ]" << std::endl;

}



#endif