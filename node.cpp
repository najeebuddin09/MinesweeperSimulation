#include "node.h"

template <class T>
node<T>::node() {
	_container = NULL;
	next = NULL;
}

template <class T>
node<T>::node(T* con) {
	_container = con;
	next = NULL;
}

template <class T>
void node<T>::setNext(node<T>* n) {
	next = n;
}

template <class T>
node<T>* node<T>::getNext() {
	return next;
}

template <class T>
T* node<T>::getContainer() {
	return _container;
}

template class node<SimMSGame>;