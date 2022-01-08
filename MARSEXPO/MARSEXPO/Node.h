#pragma once
template<typename T>
class Node
{
protected:
	T item;
	Node<T>* next;

	int priority;

public:

	Node();
	Node(const T&);
	Node(const T&, Node<T>*);
	Node(T val, int p);
	void setItem(const T&);
	void setNext(Node<T>*);
	T getdata() const;

	void setpriority(int d);
	int getpriority();

	Node<T>* getNext() const;
};
template<typename T>
Node<T>::Node()
{
	next = nullptr;
}

template<typename T>
Node<T>::Node(const T& newItem) :item(newItem)
{
	//item = newItem;
	next = nullptr;
}
template<typename T>
Node<T>::Node(const T& newItem, Node<T>* nextNode) : item(newItem)
{
	//item = newItem;
	next = nextNode;
}

template < typename T>
Node<T>::Node(T val, int p)
{
	item = val;
	priority = p;
}


template<typename T>

void Node<T>::setItem(const T& newItem)
{
	item = newItem;
} // end setItem


template<typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template<typename T>
T Node<T>::getdata() const
{
	return item;
} // end getdata

template<typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
}

template < typename T>
void Node<T>::setpriority(int d)
{
	priority = d;
}

template < typename T>
int Node<T>::getpriority()
{
	return priority;
}

