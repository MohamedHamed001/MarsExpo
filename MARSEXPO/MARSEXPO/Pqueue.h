#pragma once
#include "Node.h"

template <typename T>
class PriQ
{
private:
	Node<T>* Head;

public:
	//Constructor
	PriQ()
	{
		Head = NULL;
	}

	//Function that enqueues the elemtents sorted according to the key
	bool enqueue(T* newEntry, const int& newKey)
	{
		//Creating the new node to be inserted 
		Node<T>* temp = new Node<T>(newEntry, newKey);
		Node<T>* ptr;

		//If the entry is in the first place or the list is empty
		if (Head == NULL || (temp->getKey() < Head->getKey()))
		{
			temp->setNext(Head);
			Head = temp;
		}
		//General Case
		else
		{
			ptr = Head;
			while (ptr->getNext() != NULL && ptr->getNext()->getKey() <= temp->getKey())
				ptr = ptr->getNext();

			temp->setNext(ptr->getNext());
			ptr->setNext(temp);
		}
		return true;
	}

	//Function the takes out elements out of the queue
	bool dequeue(Node<T>*& temp)
	{
		if (isEmpty())
			return false;

		temp = Head;
		Head = Head->getNext();
		return true;
	}

	/*
	Function: peek
	copies the front of this queue to the passed param. The operation does not modify the queue.

	Input: None.
	Output: The front of the queue.
	*/
	bool peek(T& frntEntry) const
	{
		if (isEmpty())
			return false;

		frntEntry = Head->getItem();
		return true;
	}

	/*
	Function: isEmpty
	Sees whether this queue is empty.

	Input: None.
	Output: True if the queue is empty; otherwise false.
	*/
	bool isEmpty() const
	{
		return (frontPtr == nullptr);
	}
};