#pragma once

// ====================> Class Node <====================

template <typename T>
class Node
{
private:

	T data;
	Node<T>* Next;
	int Rank;

public:

	Node() {
		Next = nullptr;
		Rank = -1;
	}

	Node(T NewItem, int k = -1) {
		data = NewItem;
		Next = nullptr;
		Key = k;
	}

	void setData(T newItem)
	{
		data = newItem;
	}

	void setNext(Node<T>* nextNodePtr)
	{
		Next = nextNodePtr;
	}

	void setKey(int k) {
		Key = k;
	}

	T getData() const
	{
		return data;
	}

	Node<T>* getNext() const
	{
		return Next;
	}

	int getKey() {
		return Key;
	}

}; // ENd Node
