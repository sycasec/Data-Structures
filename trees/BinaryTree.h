/**
 *  Kyle Adrian del Castillo
 *  BSCS II : CMSC 123 - C
 *  
 *  initial commit: 11/19/2021
 *  final commit: 11/22/2021  
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "queue.h"
#include "treenode.h"

template <class T>
class BinaryTree{
private:
    TreeNode<T> *rootNode;

public:
    BinaryTree();
    BinaryTree(TreeNode<T> *node);
    ~BinaryTree();

    void setRoot(TreeNode<T>* someNode);
    TreeNode<T>* getRoot() const;

    void PreOrder(TreeNode<T>* someNode) const;
    void InOrder(TreeNode<T>* someNode) const;
    void PostOrder(TreeNode<T>* someNode) const;
    void BreadthFirst(TreeNode<T>* someNode) const;

    void Traverse(int choice);
};

/**
 *  BinaryTree default constructor
 *  brief:  sets rootnode as nullptr
 */
template <class T>
BinaryTree<T>::BinaryTree(){
    this->rootNode = nullptr;
}

/**
 *  BinaryTree with node constructor
 *  brief:  sets rootnode as TreeNode* argument
 */
template <class T>
BinaryTree<T>::BinaryTree(TreeNode<T> *node){
    this->rootNode = node;
}

/**
 *  BinaryTree deconstructor
 *  brief:  deletes root node
 */
template <class T>
BinaryTree<T>::~BinaryTree(){
    delete this->rootNode;
}

/**
 *  fn void :: setRoot(TreeNode* someNode)
 *  brief:      sets rootNode to TreeNode* argument
 *  params:     TreeNode<T>* someNode
 */
template <class T>
void BinaryTree<T>::setRoot(TreeNode<T>* someNode) {
    this->rootNode = someNode;
}

/**
 *  fn TreeNode* :: getRoot()
 *  brief:      returns pointer to rootNode
 *  params:     none
 */
template <class T>
TreeNode<T>* BinaryTree<T>::getRoot() const {
    return this->rootNode;
}


/**
 *  fn void :: PreOrder(TreeNode* someNode) const
 *  brief:      pre-order traversal of tree starting from node argument
 *  params:     TreeNode<T>* someNode
 */
template <class T>
void BinaryTree<T>::PreOrder(TreeNode<T>* someNode) const {
    if (someNode != nullptr){
        std::cout << someNode->getData() << " "; 
        PreOrder( someNode->getLeft() );
        PreOrder( someNode->getRight() );
    }
}

/**
 *  fn void :: InOrder(TreeNode* someNode) const
 *  brief:      in-order traversal of tree starting from node argument
 *  params:     TreeNode<T>* someNode
 */
template <class T>
void BinaryTree<T>::InOrder(TreeNode<T>* someNode) const {
    if (someNode != nullptr){
        InOrder( someNode->getLeft() );
        std::cout << someNode->getData() << " "; 
        InOrder( someNode->getRight() );
    }
}

/**
 *  fn void :: PostOrder(TreeNode* someNode) const
 *  brief:      Post-order traversal of tree starting from node argument
 *  params:     TreeNode<T>* someNode
 */
template <class T>
void BinaryTree<T>::PostOrder(TreeNode<T>* someNode) const {
    if (someNode != nullptr){
        PostOrder( someNode->getLeft() );
        PostOrder( someNode->getRight() );
        std::cout << someNode->getData() << " ";
    }
}


/**
 *  fn void :: BreadthFirst(TreeNode* someNode) const
 *  brief:      Breadth-First traversal of tree starting from node argument
 *  params:     TreeNode<T>* someNode
 */
template <class T>
void BinaryTree<T>::BreadthFirst(TreeNode<T>* someNode) const {
    Queue<TreeNode<T>*> nodeQueue;
    nodeQueue.enqueue( someNode );
    
    while(!nodeQueue.Qempty()){
        TreeNode<T>* currentNode = nodeQueue.front();
        std::cout << currentNode->getData() << " ";

        if ( currentNode->getLeft() != nullptr )
            nodeQueue.enqueue( currentNode->getLeft() );
        if ( currentNode->getRight() != nullptr)
            nodeQueue.enqueue( currentNode->getRight() );

        nodeQueue.dequeue();
    }
}


/**
 *  fn void :: Traverse(int choice) 
 *  brief:      wrapper function to put traversal output in nice brackets
 *  params:     int choice (1-4) : 1-PreOrder, 2-In-Order, 3-Post-Order, 4-BFS
 */
template <class T>
void BinaryTree<T>::Traverse(int choice)  {
    std::cout << "1. Pre-Order\n2. In-Order\n3. Post-Order\n4. Breadth First" << "\n- Your Choice -\n>> " << choice << std::endl;

    std::cout << "\n[ ";
    switch(choice){
        case 1:
            this->PreOrder( this->rootNode );
            break;

        case 2:
            this->InOrder( this->rootNode );
            break;

        case 3:
            this->PostOrder( this->rootNode );
            break;

        case 4:
            this->BreadthFirst( this->rootNode );
            break;
        
        default:
            break;
    }
    std::cout << "]\n" << std::endl;
}


#endif