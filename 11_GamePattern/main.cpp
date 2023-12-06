#include "ListNode.h"
#include <iostream>
using namespace std;
int main() {

	shared_ptr<ListNode> reading = make_shared<ListNode>();
	shared_ptr<ListNode> writing = reading;
	for (int i : {3, 5, 7, 9}) {
		cout << "Adding " << i << " to the list" << endl;
		writing->setValue(i);
		writing = writing->getNext();
	}
	int v = reading->getData();
	while (v > -1) {
		cout << "Read value " << v << " from the list" << endl;
		reading = reading->getNext();
		v = reading->getData();
	}



}