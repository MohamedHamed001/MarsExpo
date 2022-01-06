#pragma once
#include "Node.h"
template <typename T>
class PriQ
{
private:
	Node<T>** heap;
	int size;
	int capacity;
	int parent(int i);
	int left(int i);
	int right(int i);
	void reheap_up(int idx);
	void reheap_down(int idx);
public:
	PriQ(int c = 200);
	PriQ(const  PriQ<T>& Copy);
	bool insert(T x, int p);
	T extract_max();
	T peek();
	bool isEmpty();
	int getSize();
};

template <typename T>
PriQ<T>::PriQ(int c) {
	size = 0;
	capacity = c;
	heap = new Node<T> *[c];
}

template <typename T>
PriQ<T>::PriQ(const  PriQ<T>& Copy) {
	size = Copy.size;
	capacity = Copy.capacity;
	heap = new Node<T> *[capacity];
	for (int i = 0; i < size; i++) {
		Node<T>** temp = Copy.heap;
		T data = (temp[i])->getdata();
		int pri = (temp[i])->getpriority();
		Node<T>* node = new Node<T>(data, pri);
		heap[i] = node;
	}
}

template <typename T>
int PriQ<T>::parent(int i) {
	return (i - 1) / 2;
}

template <typename T>
int PriQ<T>::left(int i) {
	return (2 * i + 1);
}

template <typename T>
int PriQ<T>::right(int i) {
	return (2 * i + 2);
}

template <typename T>
void PriQ<T>::reheap_up(int idx) {
	while (idx > 0 && heap[parent(idx)]->getpriority() <= heap[idx]->getpriority()) {
		Node<T>* temp = heap[parent(idx)];
		heap[parent(idx)] = heap[idx];
		heap[idx] = temp;
		idx = parent(idx);
	}
}

template <typename T>
void PriQ<T>::reheap_down(int idx) {
	int max = idx;
	int l = left(idx);
	int r = right(idx);
	if (l < size && heap[l]->getpriority() >= heap[max]->getpriority()) {
		max = l;
	}
	if (r < size && heap[r]->getpriority() >= heap[max]->getpriority()) {
		max = r;
	}
	if (idx != max) {
		Node<T>* temp = heap[idx];
		heap[idx] = heap[max];
		heap[max] = temp;
		reheap_down(max);
	}
}

template <typename T>
bool PriQ<T>::insert(T x, int p) {
	if (size == capacity) return 0;
	Node<T>* node = new Node<T>(x, p);
	size++;
	heap[size - 1] = node;
	reheap_up(size - 1);
	return 1;
}

template <typename T>
T PriQ<T>::extract_max() {
	if (size <= 0) return nullptr;
	if (size == 1) {
		size--;
		return heap[0]->getdata();
	}
	Node<T>* x = heap[0];
	heap[0] = heap[size - 1];
	size--;
	reheap_down(0);
	return x->getdata();
}

template <typename T>
T PriQ<T>::peek() {

	if (isEmpty())
		return nullptr;

	return heap[0]->getdata();
}

template <typename T>
bool PriQ<T>::isEmpty() {
	return size == 0;
}

template <typename T>
int PriQ<T>::getSize() {
	return size;
}