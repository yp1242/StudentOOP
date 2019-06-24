#include <iostream>
#include "list.h"

using namespace std;

/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
	Node* temp = new Node(d, nullptr);
	Node* counter = head;
	if (counter != nullptr) {
		while (counter->next != nullptr) {
			counter = counter->next;
		}
		counter->next = temp;
	}
	else {
		head=temp;
	}	
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
	while (curr != nullptr) {
		cout << curr->data << ' ';
		curr = curr->next;
	}
	cout << endl;
	
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	Node* temp = new Node(d,head);
	head = temp;
	
}

/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
	if (head != nullptr) {
		while (head->next != nullptr) {
			head = head->next;
		}
		return head;
	}
}

/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
	os << nd->data << endl;
	return os;
}