/*
*   Kyle Adrian del Castillo
*   BSCS II : CMSC 123 - C
*   10/21/2021
*/

#include "Stack.h"

int main(){
    Stack<int> stack;
    std::cout << "testing <int> stack" << std::endl;
    stack.printList();
    stack.push(1);
    stack.peek();
    stack.pop();
    stack.peek();
    stack.push(2);
    stack.peek();
    stack.push(3);
    stack.push(4);
    stack.pop();
    stack.printList();

    std::cout << "\n\ntesting Stack<std::string>";
    std::cout << std::endl;
    Stack<std::string> StringStack;
    StringStack.push("Hello");
    StringStack.peek();
    StringStack.push("World");
    StringStack.peek();
    StringStack.push("Foo");
    StringStack.peek();
    StringStack.push("Bar");
    StringStack.pop();

    StringStack.printList();
}
