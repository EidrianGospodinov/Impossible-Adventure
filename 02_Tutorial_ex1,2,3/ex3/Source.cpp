#include <iostream>
using std::cout;
using std::endl;

struct DListNode {
	int data;
	DListNode* next;
	DListNode* previous;
};

DListNode* makeNode(int value) {
	// TO DO: actually create a node
	DListNode *newNode = new DListNode;
	newNode->data = value;
	newNode->next = nullptr;
	newNode->previous = nullptr;
	return newNode;
}

void printList(DListNode* n) {
	// TO DO: print nodes starting at n
	while (n != nullptr) {
		cout << n->data<<"\t";
		n = n->next;
	}
	cout << endl;
}

DListNode* find(int value, DListNode* n) {
	// TO DO: search value starting at n
	while (n != nullptr) {
		if (n->data == value) {
			return n;
		}
		n=n->next;
	}
	return nullptr;
}

void insertAfter(int newData, DListNode* n) {
	// TO DO: insert a new node after n
	if (n != nullptr) {

	DListNode* newNode = new DListNode;
	newNode->data = newData;
	//all the pointers should point somewhere!

	newNode->next = n->next;//point the new node to the same thing the old node was pointing to
	newNode->previous = n;

	n->next = newNode;//point the old node to the new node

	}
}

int main() {
	DListNode* first = makeNode(0);
	insertAfter(1, first);
	insertAfter(3, first);
	insertAfter(4, first);
	printList(first);  // Should print "0 4 3 1"
	DListNode* n = find(1, first);
	insertAfter(9, n);
	printList(first);  // Should print "0 4 3 2 1"
	// Try adding some more tests
}


