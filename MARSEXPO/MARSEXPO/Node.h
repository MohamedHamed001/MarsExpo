#pragma once
template<typename T>
class Node
{
protected:
	T item;	
	Node<T>* next;
public:

	Node();
	Node(const T&);
	Node(const T&, Node<T>*);
	void setItem(const T&);
	void setNext(Node<T>* );
	T getItem() const;
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
T Node<T>::getItem() const
{
	return item;
} // end getItem

template<typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
}
