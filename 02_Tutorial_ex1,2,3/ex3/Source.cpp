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
	
	if(newNode->next!=nullptr)				//important withouth setting up the next prev.
		newNode->next->previous = newNode;  //all the data after the removal will dissapear as well
											//because thhe point will point at the first node from where you start
											//aka: 0 from "makeNode" function

	}
	
}
void remove(DListNode* n) {
	if (n != nullptr) {

		if (n->next != nullptr) {
			n->next->previous = n->previous;
		}
		if (n->previous != nullptr) {
			n->previous->next = n->next;
		}
		delete n;
	}


	
}

int main() {
	DListNode* first = makeNode(0);
	insertAfter(1, first);
	insertAfter(3, first);
	insertAfter(4, first);
	/*insertAfter(5, first);*/
	printList(first);  // Should print "0 4 3 1"
	DListNode* n = find(3, first);
	remove(n);
	//insertAfter(7, n);
	printList(first);  // Should print "0 4 3 2 1"
	// Try adding some more tests
}


