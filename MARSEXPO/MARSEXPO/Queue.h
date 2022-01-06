#pragma once
#include<iostream>
#include "Node.h"


template <typename T>
class Queue
{
	Node<T>* frtPtr;
	Node<T>* backPtr;
public:
	Queue()
	{
		frtPtr = nullptr;
		backPtr = nullptr;
	}
	void enqueue(T* d)
	{
		Node<T>* newPtr = new Node<T>(d);
		if (!frtPtr)
		{
			frtPtr = newPtr;
			backPtr = frtPtr;
			return;
		}
		backPtr->setNext(newPtr);
		backPtr = backPtr->getNext();
	}
	bool dequeue(Node<T>*& temp)
	{
		if (isEmpty())
			return false;
		if (frtPtr == backPtr)
		{
			temp = frtPtr;
			frtPtr = nullptr;
			backPtr = nullptr;
			return true;
		}
		temp = frtPtr;
		frtPtr = frtPtr->getNext();
		return true;

	}

	bool peek(Node<T>*& temp)
	{
		if (isEmpty())
			return false;
		temp = frtPtr;
		return true;
	}

	bool isEmpty()
	{
		return(frtPtr == nullptr);
	}
};