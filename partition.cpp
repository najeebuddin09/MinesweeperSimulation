#include "partition.h"

template <class T>
Partition<T>::Partition() {
    head = NULL;
}

template <class T>
void Partition<T>::push(T* g) {
    node<T>* newNode = new node<T>(g);

    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse till end of list
    node<T>* temp = head;
    while (temp->getNext() != NULL) {

        // Update temp
        temp = temp->getNext();
    }

    temp->setNext(newNode);
}

// remove item from head
template <class T>
void Partition<T>::pop() {
    node<T>* temp1 = head;
	head = head->getNext();
	delete temp1;
	return;
}

template <class T>
node<T>* Partition<T>::getHead() {
    return head;
}

template class Partition<SimMSGame>;

