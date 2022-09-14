/*
*   Kyle Adrian del Castillo
*   BSCS II : CMSC 123 - C
*   11/14/2021
*/

#include "Queue.h"
#include "Deque.h"

int main(){
    std::cout << "\nTesting printList and printItem()\n" << std::endl;
    Queue<int> testQ;
    testQ.enqueue(1);
    testQ.enqueue(2);
    testQ.enqueue(3);
    testQ.printList();
    testQ.printItem(testQ.front());


    std::cout << "\nTesting Queue\n" << std::endl;
    Queue<int> myQ;
    myQ.enqueue(1);
    myQ.printItem(myQ.front());
    myQ.enqueue(2);
    myQ.printList();
    myQ.printItem(myQ.dequeue());
    myQ.printItem(myQ.front());


    std::cout << "\nTesting Dequeue\n" << std::endl;
    Dequeue<int> myDQ;
    myDQ.enqueueBack(420);
    myDQ.printItem(myDQ.front());
    myDQ.enqueueFront(68);
    myDQ.printItem(myDQ.front());
    myDQ.enqueueFront(67);

    myDQ.printItem(myDQ.dequeueBack());
    myDQ.printList();
    myDQ.printItem(myDQ.back());
    myDQ.dequeueFront();
    myDQ.printItem(myDQ.front());

}
