/**
 *  Kyle Adrian del Castillo
 *  BSCS II : CMSC 123 - C
 *  
 *  initial commit: 11/22/2021
 *  final commit: 11/22/2021  
 */


#include "BinaryTree.h"

int main(){
    BinaryTree<int> BinTree;

    TreeNode<int> Root(1), A(2),B(3),C(4),D(5),E(6),F(7);

    Root.setChildren(&A, &B);
    A.setChildren(&C, &D);
    B.setChildren(&E, &F);

    BinTree.setRoot(&Root);

    BinTree.Traverse(4);
    BinTree.Traverse(1);


    TreeNode<std::string> Groot("Root"), G("G"), H("H"), I("I"),  J("J"), K("K"), L("L"), M("M"), N("N");

    Groot.setChildren(&G, &N);
    G.setChildren(&H,&I);
    N.setChildren(&J,&K);
    H.setLeft(&L);
    K.setLeft(&M);

    BinaryTree<std::string> StringBinaryTree(&Groot);

    StringBinaryTree.Traverse(4);
    StringBinaryTree.Traverse(2);
    StringBinaryTree.Traverse(3);
}