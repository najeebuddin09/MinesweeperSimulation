#pragma once
#include "node.h"
#include "SimMSGame.h"

// Linked List
template<class T>
class Partition {
	node<T>* head;
public:
	Partition();
	void push(T* g);
	void pop();
	node<T>* getHead();
};

