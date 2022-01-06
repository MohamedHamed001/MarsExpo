#pragma once
#include"Node.h"
template<class T>
class List
{
	Node<T>* Head;	//pointer points to the first node in the list
	Node<T>* Tail;	//pointer points to the last node in the list
	int count;		//current count of list item
	Node<T>* getNodeAt(int) const;//get pointer which refers to this position

public:
	List();
	List(const List<T>&); //copy constructor
	bool isEmpty()const;
	int getLength()const;
	T getEntry(int)const;
	bool insert(const int, const T&);
	bool remove(int);
	void clear();
	int getIndexOf(const T&)const;
	virtual ~List();
};

template<class T>
List<T>::List()
{
	Head = nullptr;
	Tail = nullptr;
	count = 0;
}

template<class T>
Node<T>* List<T>::getNodeAt(int position)const
{
	Node<T>* temp = Head;
	if (count < position || position <= 0)
	{
		return nullptr;
	}
	else
	{
		temp = Head;
		for (int i = 1; i < position; i++)
		{
			temp = temp->getNext();
		}
		return temp;
	}
}

template<class T>
List<T>::List(const List<T>& L2)
{
	Head = Tail = nullptr;
	Node<T>* original = L2.Head;
	if (original == nullptr)
	{
		return;
	}
	int i = 1;
	while (original)
	{
		this->insert(i, original->getItem());
		original = original->getNext();
		i++;
	}
	count = L2.count;
}

template<class T>
bool List<T>::isEmpty()const
{
	if (Head == nullptr)
	{
		return true;
	}
	return false;
}

template<class T>
int List<T>::getLength()const
{
	return count;
}

template<class T>
T List<T>::getEntry(int pos)const
{
	Node<T>* target = getNodeAt(pos);
	if (target)
		return target->getItem();
}

template<class T>
bool List<T>::insert(const int index, const T& item)
{
	if (count + 1 < index || index <= 0)
		return false;
	Node<T>* newNode = new Node<T>(item);
	if (index == 1)
	{
		newNode->setNext(Head);
		Tail = newNode;
		Head = newNode;
	}
	else if (index == count + 1)
	{
		Tail->setNext(newNode);
		Tail = newNode;
	}
	else
	{
		Node<T>* temp = Head;
		for (int i = 1; i < index - 1 && temp->getNext(); i++)
		{
			temp = temp->getNext();
		}
		if (temp->getNext() == Tail)
		{
			temp->setNext(newNode);
			newNode->setNext(Tail);
			return true;
		}
		newNode->setNext(temp->getNext());
		temp->setNext(newNode);
	}
	count++;
	return true;
}


template<class T>
bool List<T>::remove(int pos)
{
	if (isEmpty())
		return false;
	Node<T>* temp = getNodeAt(pos);
	if (temp)
	{
		Node<T>* target = Head;
		if (temp == Head)
		{
			Head = Head->getNext();
			delete temp;
		}
		else if (temp == Tail)
		{
			while (target->getNext() != Tail)
			{
				target = target->getNext();
			}
			Tail = target;
			Tail->setNext(nullptr);
			delete temp;
		}
		else
		{
			while (target->getNext() != temp)
			{
				target = target->getNext();
			}
			target->setNext(temp->getNext());
			delete temp;
		}
		count--;
		return true;
	}
	return false;
}


template<class T>
void List<T>::clear()
{
	if (!isEmpty())
	{
		while (Head)
		{
			Node<T>* temp = Head;
			Head = Head->getNext();
			delete temp;
		}
		count = 0;
	}
}

template<class T>
int List<T>::getIndexOf(const T& target)const
{
	bool found = false;
	Node<T>* targetPtr = Head;
	int position = -1;
	int count = 1;
	while (!found && targetPtr)
	{
		if (targetPtr->getItem() == target)
		{
			found = true;
			position = count;
		}
		else
			targetPtr = targetPtr->getNext();
		count++;
	}
	return position;
}

template<class T>
List<T>::~List()
{
	clear();
}