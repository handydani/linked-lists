// pa2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>

class Node {
public:
	Node* next;
	int val;
	Node();
};

Node::Node() {
	next = NULL;
	val = -1;
}

class LinkedList {
private:
	Node* head;
	int size;
public:
	LinkedList();
	void append(int data);
	void remove(int index, int data);
	void add(int index, int data);
	Node* getElementAt(int index);
	void print();
};

LinkedList::LinkedList() {
	head = NULL;
	size = 0;
}

Node* LinkedList::getElementAt(int index) {
	if (index < 0 || index > size - 1 || head == NULL) {
		return NULL;
	}
	Node* current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	return current;
}

void LinkedList::append(int data) {
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

void LinkedList::add(int index, int data) {
	if (index<0 || index>size) {
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

void LinkedList::remove(int index, int data) {
	if (index<0 || index >= size) {
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
	LinkedList* linkedList = new LinkedList();
	for (int i = 0; i < 5; i++) {
		linkedList->append(i);
	}
	linkedList->print();
	//henry sux lol 
	return 0;
}
