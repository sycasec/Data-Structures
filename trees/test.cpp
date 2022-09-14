/*
*   Kyle Adrian del Castillo
*   BSCS II : CMSC 123 - C
*
*   initial commit: 11/26/2021   
*   final commit:   11/30/2021
*/

#include "GeneralTree.h"

int main(){

    std::cout << "\nTesting GeneralTreeNode<int>" << std::endl;

    //initiating Nodes<int> root, A -> H, maxDepth [1,2..., 10]

    GeneralTreeNode<int> root(1), A(2), B(3), C(4), D(5), E(6), F(7), G(8), H(9), maxDepth(10);
    root.addChild(&A);
    root.addChild(&B);
    root.addChild(&C);
    B.addChild(&D);
    B.addChild(&E);
    C.addChild(&F);
    C.addChild(&G);
    C.addChild(&H);
    H.addChild(&maxDepth);


    //initializing GeneralTree<int> someTree, set someTree->rootNode = &root
    GeneralTree<int> someTree(&root);
    std::cout << "Testing children functionality, displaying root.children" << std::endl;
    root.children.printList();

    std::cout << "Testing breadth first traversal" <<std::endl;
    someTree.BreadthFirst();


    
    std::cout << "\nTesting GeneralTreeNode<std::string>" << std::endl;
    //initiating Nodes<string> Groot, I -> P
    GeneralTreeNode<std::string> Groot("root"), I("I"), J("J"), K("K"), L("L"), M("M"), N("N"), O("O"), P("P");
    Groot.addChild(&I);
    Groot.addChild(&J);
    I.addChild(&K);
    I.addChild(&M);
    I.addChild(&P);
    J.addChild(&N);
    N.addChild(&O);
    

    //initializing GeneralTree<string> stringTree, set stringTree->root = &Groot
    GeneralTree<std::string> stringTree(&Groot);

    stringTree.BreadthFirst();
}

