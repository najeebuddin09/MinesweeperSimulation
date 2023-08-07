#pragma once

#include "node.h"
#include "SimMSGame.h"

template <class T>
class node {
	T* _container;
	node<T>* next;
public:
	node();
	node(T*);
	void setNext(node<T>* n);
	node<T>* getNext();
	T* getContainer();
};

