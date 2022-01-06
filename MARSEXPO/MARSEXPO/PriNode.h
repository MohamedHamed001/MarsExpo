#pragma once
template<class T>
class PriorityNode
{
	int priority;
	T item;
	PriorityNode<T>* next;
	
public:

	//Construtors
	PriorityNode(const int);								//Recives priority only
	PriorityNode(const T&, const int);						//Recives item and priority 
	PriorityNode(const T&, PriorityNode<T>*, const int);	//Recives item ,next and priority

	//Additional Setters and getters
	void setPriority(const int);
	int getPriority() const;

	void setNext(PriorityNode<T>*);
	PriorityNode<T>* getNext() const;

	void setItem(const T&);
	T getItem() const;
};

template<class T>
PriorityNode<T>::PriorityNode(const int recivedPriority) :priority(recivedPriority), next(nullptr)
{
}

template<class T>
PriorityNode<T>::PriorityNode(const T& recivedItem, const int recivedPriority) : item(recivedItem), priority(recivedPriority), next(nullptr)
{
}

template<class T>
PriorityNode<T>::PriorityNode(const T& recivedItem, PriorityNode<T>* recivedNext, const int recivedPriority) : item(recivedItem), next(recivedNext), priority(recivedPriority)
{
}

template<class T>
void PriorityNode<T>::setPriority(const int recivedPriority)
{
	priority = recivedPriority;
}

template<class T>
int PriorityNode<T>::getPriority() const
{
	return priority;
}

template<class T>
void PriorityNode<T>::setNext(PriorityNode<T>* recivedNext)
{
	next = recivedNext;
}

template<class T>
PriorityNode<T>* PriorityNode<T>::getNext() const
{
	return next;
}

template<class T>
void PriorityNode<T>::setItem(const T& recivedItem)
{
	item = recivedItem;
}

template<class T>
T PriorityNode<T>::getItem() const
{
	return item;
}