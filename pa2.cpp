// pa2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
template <typename T>
class Node {
public:
	Node* next;
	T val;
	Node();
};

Node::Node() {
	next = NULL;
	val = -1;
}
template <typename T>
class LinkedList {
private:
	Node* head;
	T size;
public:
	LinkedList();
	void append(T data);
	void remove(T index, T data);
	void add(T index, T data);
	Node* getElementAt(T index);
	void print();
};

LinkedList::LinkedList() {
	head = NULL;
	size = 0;
}

Node* LinkedList::getElementAt(size_t index) {
	if (index > size - 1 || head == NULL) {
		return NULL;
	}
	Node* current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	return current;
}
template <typename T>
void LinkedList::append(T data) {
	Node* current = head;

	if (head == NULL) {
		head = new Node();
		head->val = data;
		head->next = NULL;
		size++;
		return;
	}

	while (current->next != NULL) {
		current = current->next;
	}

	current->next = new Node();
	current->next->val = data;
	size++;
	// -> means (*current)
}

void LinkedList::print() {
	Node* current = head;
	while (current != NULL) {
		std::cout << current->val << "-> ";
		current = current->next;
	}
	std::cout << "NULL" << std::endl;
}
template <typename T>
void LinkedList::add(size_t index, T data) {
	if (index>size) {
		return;
	}
	Node *dummy = new Node();
	dummy->next = head;
	Node *current = dummy;
	for (int i = 0; i<index; i++) {
		current = current->next;
	}
	Node *temp = new Node();
	temp->val = data;
	temp->next = current->next;
	current->next = temp;
	size++;
	head = dummy;
	delete dummy;
}
template <typename T>
void LinkedList::remove(size_t index, T data) {
	if (index >= size) {
		return;
	}
	Node *dummy = new Node();
	dummy->next = head;
	Node *current = dummy;
	for (int i = 0; i<index; i++) {
		current = current->next;
	}
	Node *temp = current->next;
	current->next = current->next->next;
	size--;
	head = dummy;
	delete temp;
	delete dummy;
}

int main() {
	LinkedList<int>* linkedList = new LinkedList();
	for (int i = 0; i < 5; i++) {
		linkedList->append(i);
	}
	linkedList->print();
	//henry sux lol
	return 0;
}
