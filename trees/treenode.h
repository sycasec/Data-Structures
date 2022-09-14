/*
*   Kyle Adrian del Castillo
*   BSCS II : CMSC 123 - C
*
*   initial commit: 11/19/2021   
*   final commit:   11/22/2021
*/

#ifndef TREENODE_H
#define TREENODE_H

template <class T>
class TreeNode{

private:
    TreeNode<T> *right;
    TreeNode<T> *left;
    T data;

public:
    TreeNode();
    TreeNode(T data);

    void setChildren(TreeNode<T>* leftNode, TreeNode<T>* rightNode);

    void setData(T data);
    void setRight(TreeNode<T>* someNode);
    void setLeft(TreeNode<T>* someNode);

    T getData() const;
    TreeNode<T>* getRight() const;
    TreeNode<T>* getLeft() const;
};

/*
    TreeNode default constructor
    brief - instantiate an empty node
          - sets left and right to nullptr
*/
template <class T>
TreeNode<T>::TreeNode(){
    this->right = nullptr;
    this->left = nullptr;
}


/*
    TreeNode constructor with Data
    brief - accepts <T> type data and sets own data to data arg.
          - sets children nodes to nullptr
*/
template <class T>
TreeNode<T>::TreeNode(T data){
    this->data = data;
    this->right = nullptr;
    this->left = nullptr;
}


/**
 *  fn void::setChildren(leftNode, rightNode)
 *  brief:      sets children node to passed arguments
 *  params:     TreeNode<T>* leftNode, TreeNode<T>* rightNode
 */
template <class T>
void TreeNode<T>::setChildren(TreeNode<T>* leftNode, TreeNode<T>* rightNode){
    this->left = leftNode;
    this->right = rightNode;
}

/**
 *  fn void::setData(T data)
 *  brief:      sets data to passed argument
 *  params:     T data (same type as initiation)
 */
template <class T>
void TreeNode<T>::setData(T data){
    this->data = data;
}

/**
 *  fn void::setRight(TreeNode* someNode)
 *  brief:      sets right child node to passed argument
 *  params:     TreeNode<T>* someNode
 */
template <class T>
void TreeNode<T>::setRight(TreeNode<T>* someNode){
    this->right = someNode;
}

/**
 *  fn void::setLeft(TreeNode* someNode)
 *  brief:      sets left child node to passed argument
 *  params:     TreeNode<T>* someNode
 */
template <class T>
void TreeNode<T>::setLeft(TreeNode<T>* someNode){
    this->left = someNode;
}

/**
 *  fn T :: getData()
 *  brief:      returns data stored in node
 *  params:     none
 */
template <class T>
T TreeNode<T>::getData() const{
    return this->data;
}

/**
 *  fn TreeNode* :: getRight()
 *  brief:      returns pointer to right child node
 *  params:     none
 */
template <class T>
TreeNode<T>* TreeNode<T>::getRight() const{
    return this->right;
}

/**
 *  fn TreeNode* :: getLeft()
 *  brief:      returns pointer to left child node
 *  params:     none
 */
template <class T>
TreeNode<T>* TreeNode<T>::getLeft() const{
    return this->left;
}

#endif
