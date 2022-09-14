/**
*   Kyle Adrian del Castillo
*   BSCS II :: CMSC 123 - C
*   11/14/2021
*/

#include "CircularArrayQ.h"
#include "CircularArrayDQ.h"

using namespace std;

int main(){
    CircularArrayQueue<int> *CircularQ = new CircularArrayQueue<int>(5);

    /*
    Execution halts when underflow is thrown!

    std::cout << CircularQ->dequeue() << std::endl;
    */
    std::cout << "-----------\nQueue test\n-----------" << std::endl;
    CircularQ->enqueue(1);
    CircularQ->enqueue(2);
    CircularQ->printItem(CircularQ->peekFront());
    CircularQ->dequeue();
    CircularQ->printItem(CircularQ->peekFront());
    CircularQ->enqueue(3);
    CircularQ->enqueue(4);
    CircularQ->printItem(CircularQ->getSize());
    CircularQ->printList();
    CircularQ->enqueue(5);
    CircularQ->enqueue(6);
    CircularQ->printList();


    std::cout << "-----------\nDeque test\n-----------" << std::endl;
    CircularArrayDeque<int> *CircularDQ = new CircularArrayDeque<int>(5);

    CircularDQ->EnqueueBack(1);
    CircularDQ->EnqueueBack(2);
    CircularDQ->printItem(CircularDQ->peekFront());
    CircularDQ->EnqueueFront(3);
    CircularDQ->printItem(CircularDQ->peekFront());
    CircularDQ->EnqueueBack(4);
    CircularDQ->EnqueueBack(5);
    cout << "Peek rear\n>> ";
    CircularDQ->printItem(CircularDQ->peekRear());
    cout << "Peek front\n>> ";
    CircularDQ->printItem(CircularDQ->peekFront());
    CircularDQ->printList();
    CircularDQ->printItem(CircularDQ->DequeueRear());
    CircularDQ->printItem(CircularDQ->DequeueFront());
    CircularDQ->printList();
}
