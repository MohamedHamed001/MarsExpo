#pragma once
#include "Node.h"
template <typename T>
class Queue
{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	Queue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	int getSize();
	//void print() const;
	~Queue();

	//copy constructor
	Queue(const Queue<T>& LQ);
};

template <typename T>
Queue<T>::Queue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}


template <typename T>
bool Queue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

template <typename T>
bool Queue<T>::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new Node
	if (isEmpty())	//special case if this is the first Node to insert
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty

	backPtr = newNodePtr; // New Node is the last Node2 now
	return true;
} // end enqueue

template <typename T>
bool Queue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* NodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getdata();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (NodeToDeletePtr == backPtr)	 // Special case: last Node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued Node
	delete NodeToDeletePtr;

	return true;

}

template <typename T>
Queue<T>::~Queue()
{
	T temp;

	//Free (Dequeue) all Node2s in the queue
	while (dequeue(temp));
}

template <typename T>
Queue<T>::Queue(const Queue<T>& LQ)
{
	Node<T>* NodePtr = LQ.frontPtr;
	if (!NodePtr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	//insert the first Node
	Node<T>* ptr = new Node<T>(NodePtr->getdata());
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();

	//insert remaining Nodes
	while (NodePtr)
	{
		Node<T>* ptr = new Node<T>(NodePtr->getdata());
		backPtr->setNext(ptr);
		backPtr = ptr;
		NodePtr = NodePtr->getNext();
	}
}

template <typename T>
bool Queue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getdata();
	return true;

}

template <typename T>
int Queue<T>::getSize()
{
	Node<T>* NodePtr = frontPtr;
	int s(0);
	while (NodePtr) {
		s++;
		NodePtr = NodePtr->getNext();
	}
	return s;
}